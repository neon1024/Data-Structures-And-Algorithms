#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    /* Constructs the object Bag
     * Time Complexity:
     * Best Case: Theta(1)
     * Average Case: Theta(1)
     * Worst Case: Theta(1)
     */
    this->capacity_unique_elements = DEFAULT_CAPACITY_UNIQUE_ELEMENTS;
    this->size_unique_elements = 0;
    this->unique_elements = new TElem[this->capacity_unique_elements];

    this->capacity_positions = DEFAULT_CAPACITY_POSITIONS;
    this->size_positions = 0;
    this->positions = new TElem[this->capacity_positions];
}

void Bag::add(TElem elem) {
    /* Adds a given element to the Bag
     * Time Complexity:
     * Best Case: Theta(1)
     * Average Case: Theta(max{n, m})
     * Worst Case: Theta(n + m)
     * n: the size of U
     * m: the size of P
     */
    /*
        Implementation:
        if elem already exists in U:
            if P capacity is full:
                resize P
            add to P the position where elem was found in U
        else, if elem does not exist in U:
            if capacity of U is full:
                resize U
            add elem
            if P capacity is full:
                resize P
            add this->size_capacity-1 to P
    */
    // check if elem already in U
    bool elem_already_exists = false;
    int elem_position = -1;

    for(int index = 0; index < this->size_unique_elements && !elem_already_exists; index++) {
        if(this->unique_elements[index] == elem) {
            elem_already_exists = true;
            elem_position = index;
        }
    }

    if(elem_already_exists) {
        // update P
        // check if P capacity is full
        if(this->size_positions >= this->capacity_positions) {
            // resize P
            Bag::resize_positions();
        }
        // add position to P
        Bag::add_to_positions(elem_position);
    }
    else {
        // update U
        // check if U capacity is full
        if(this->size_unique_elements >= this->capacity_unique_elements) {
            // resize U
            Bag::resize_unique_elements();
        }
        // add elem to U
        Bag::add_to_unique_elements(elem);
        // update P
        // check if P capacity is full
        if(this->size_positions >= this->capacity_positions) {
            // resize P
            Bag::resize_positions();
        }
        // add position to P
        Bag::add_to_positions(this->size_unique_elements-1);
    }
}

bool Bag::remove(TElem elem) {
    /* Removes a given element from the Bag
     * Time Complexity:
     * Best Case: Theta(min{n, m})
     * Average Case: Theta(m + n)
     * Worst Case: Theta(n + m)
     * n: the size of U
     * m: the size of P
     */
    int elem_position = -1;

    for(int index = 0; index < this->size_unique_elements; index++) {
        if(this->unique_elements[index] == elem) {
            elem_position = index;
            break;
        }
    }

    if(elem_position == -1) {
        return false;
    }
    // remove all occurrences of elem_position from P
    Bag::remove_first_occurrence_from_positions(elem_position);

    // if elem_position no longer in P, then remove elem from U
    if(Bag::nrOccurrences(elem) == 0) {
        // remove elem from U
        Bag::remove_from_unique_elements(elem);
        Bag::rearrange_positions(elem_position);
    }

    return true;
}

int Bag::removeAllOccurrences(TElem elem) {
    /* Removes all the occurrences of a given element from the Bag
     * Returns the number of elements that were removed from the Bag
     * Time Complexity:
     * Best Case: Theta(min{n, m})
     * Average Case:
     * Worst Case: Theta(n + (n + m)*m)
     * n: the size of U
     * m: the size of P
     */
    int elem_position = -1;

    for(int index = 0; index < this->size_unique_elements; index++) {
        if(this->unique_elements[index] == elem) {
            elem_position = index;
            break;
        }
    }

    if(elem_position == -1) {
        return 0;
    }

    int number_of_removed_elements{0};

    while(Bag::nrOccurrences(elem) != 0) {
        Bag::remove_first_occurrence_from_positions(elem_position);
        number_of_removed_elements++;
    }

    Bag::remove_from_unique_elements(elem);
    Bag::rearrange_positions(elem_position);

    return number_of_removed_elements;
}

void Bag::rearrange_positions(int index) {
    /* Rearrange the positions from P (modify their value) after an element was
     * removed from U and the order from P shifted
     * Time Complexity:
     * Best Case: Theta(m)
     * Average Case: Theta(m)
     * Worst Case: Theta(m)
     * m: the size of P
     */
    for(int i = 0; i < this->size_positions; i++) {
        if(this->positions[i] > index) {
            this->positions[i]--;
        }
    }
}

bool Bag::search(TElem elem) const {
    /* Returns True if a given element is in the Bag, False otherwise
     * Time Complexity:
     * Best Case: Theta(1): found on the first positions
     * Average Case: Theta(n)
     * Worst Case: Theta(n)
     * n: the size of U
     */
    for(int index = 0; index < this->size_unique_elements; index++) {
        if(this->unique_elements[index] == elem) {
            return true;
        }
    }
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
    /* Returns the number of occurrences of a given element from the Bag
     * Time Complexity:
     * Best Case: Theta(min{n, m}): either traverses U and doesn't find the element and returns or traverses P
     * Average Case: Theta(n + m)
     * Worst Case: Theta(n + m)
     * n: the size of U
     * m: the size of P
     */
    int elem_position = -1;

    for(int index = 0; index < this->size_unique_elements; index++) {
        if(this->unique_elements[index] == elem) {
            elem_position = index;
            break;
        }
    }

    if(elem_position == -1) {
        return 0;
    }

    int elem_occurrences = 0;

    for(int index = 0; index < this->size_positions; index++) {
        if(this->positions[index] == elem_position) {
            elem_occurrences += 1;
        }
    }

	return elem_occurrences;
}

int Bag::size() const {
    /* Returns the size of the Bag
     * Time Complexity:
     * Best Case: Theta(1)
     * Average Case: Theta(1)
     * Worst Case: Theta(1)
     */
	return this->size_positions;
}

bool Bag::isEmpty() const {
    /* Returns True if the Bag is empty, False otherwise
     * Time Complexity:
     * Best Case: Theta(1)
     * Average Case: Theta(1)
     * Worst Case: Theta(1)
     */
	return this->size_unique_elements == 0 && this->size_positions == 0;
}

void Bag::remove_from_unique_elements(TElem elem) {
    /* Removes a given element from U
     * Time Complexity:
     * Best Case: Theta(1)
     * Average Case: Theta(n)
     * Worst Case: Theta(n)
     * n: the size of U
     */
    for(int index = 0; index < this->size_unique_elements; index++) {
        if(this->unique_elements[index] == elem) {
            for(int position = index+1; position < this->size_unique_elements; position++) {
                this->unique_elements[position-1] = this->unique_elements[position];
            }
            this->size_unique_elements -= 1;
            break;
        }
    }
}

void Bag::remove_first_occurrence_from_positions(int position) {
    /* Removes the first occurrence of a given element from P (position)
     * Time Complexity:
     * Best Case: Theta(m)
     * Average Case: Theta(m)
     * Worst Case: Theta(m)
     * m: the size of P
     */
    for(int index = 0; index < this->size_positions; index++) {
        if(this->positions[index] == position) {
            for(int target = index+1; target < this->size_positions; target++) {
                this->positions[target-1] = this->positions[target];
            }
            this->size_positions--;
            break;
        }
    }
}

void Bag::add_to_unique_elements(TElem elem) {
    /* Adds a new element (that is not already in U) in U
     * Time Complexity:
     * Best Case: Theta(1)
     * Average Case: Theta(1)
     * Worst Case: Theta(1)
     */
    this->unique_elements[this->size_unique_elements] = elem;
    this->size_unique_elements += 1;
}

void Bag::add_to_positions(int index) {
    /* Adds a new element (that is an index mapped to an unique element in U) in P
     * Time Complexity:
     * Best Case: Theta(1)
     * Average Case: Theta(1)
     * Worst Case: Theta(1)
     */
    this->positions[this->size_positions] = index;
    this->size_positions++;
}

void Bag::resize_unique_elements() {
    /* Resize the dynamic array that holds the unique elements
     * Time Complexity:
     * Best Case: Theta(1)
     * Average Case: Theta(n)
     * Worst Case: Theta(n)
     * n: the size of U
     */
    int new_capacity;

    if(this->capacity_unique_elements == 0) {
        new_capacity = 1;
    } else {
        new_capacity = this->capacity_unique_elements * 2;
    }

    TElem* resized_elements = new TElem[new_capacity];

    for(int index = 0; index < this->size_unique_elements; index++) {
        resized_elements[index] = this->unique_elements[index];
    }

    delete[] this->unique_elements;

    this->unique_elements = resized_elements;
    this->capacity_unique_elements = new_capacity;
}

void Bag::resize_positions() {
    /* Resize the dynamic array that holds the unique elements
     * Time Complexity:
     * Best Case: Theta(1)
     * Average Case: Theta(m)
     * Worst Case: Theta(m)
     * m: the size of P
     */
    int new_capacity;

    if(this->capacity_positions == 0) {
        new_capacity = 1;
    } else {
        new_capacity = this->capacity_positions * 2;
    }

    TElem* resized_elements = new TElem[new_capacity];

    for(int index = 0; index < this->size_positions; index++) {
        resized_elements[index] = this->positions[index];
    }

    delete[] this->positions;

    this->positions = resized_elements;
    this->capacity_positions = new_capacity;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

Bag::~Bag() {
    // delete the U links
    delete[] this->unique_elements;
    // delete the P links
    delete[] this->positions;
}
