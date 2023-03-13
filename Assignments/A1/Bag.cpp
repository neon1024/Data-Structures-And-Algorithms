#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    this->capacity_unique_elements = DEFAULT_CAPACITY_UNIQUE_ELEMENTS;
    this->size_unique_elements = 0;
    this->unique_elements = new TElem[this->capacity_unique_elements];

    this->capacity_positions = DEFAULT_CAPACITY_POSITIONS;
    this->size_positions = 0;
    this->positions = new TElem[this->capacity_positions];
}

void Bag::add(TElem elem) {
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
    /*
        Implementation:
        check if elem is in U
        if is not, return false
        if is in U, then:
            find the position where elem appears in U
            remove the first occurrence of this position from P
            if no occurrences of this position appear in P anymore, then remove elem from U
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
    }

    return true;
}

bool Bag::search(TElem elem) const {
    // check if elem is in U
    for(int index = 0; index < this->size_unique_elements; index++) {
        if(this->unique_elements[index] == elem) {
            return true;
        }
    }
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
    /*
        Implementation:
        if elem in U:
            find how many times the position appears in P
            return that number
        else, if elem not in U:
            return 0
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
    // the size is the number of elements in P
	return this->size_positions;
}

bool Bag::isEmpty() const {
    // is empty if size is 0
	return this->size_unique_elements == 0 && this->size_positions == 0;
}

void Bag::remove_from_unique_elements(TElem elem) {
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
    for(int index = 0; index < this->size_positions; index++) {
        if(this->positions[index] == position) {
            for(int target = index+1; target < this->size_positions; target++) {
                this->positions[target-1] = this->positions[target];
            }
            this->size_positions -= 1;
            break;
        }
    }
}

void Bag::add_to_unique_elements(TElem elem) {
    this->unique_elements[this->size_unique_elements] = elem;
    this->size_unique_elements += 1;
}

void Bag::add_to_positions(int index) {
    this->positions[this->size_positions] = index;
    this->size_positions += 1;
}

void Bag::resize_unique_elements() {
    this->capacity_unique_elements = 2* this->capacity_unique_elements;
    TElem* resized_unique_elements = new TElem[this->capacity_unique_elements];

    // copy the elements into the new dynamic array
    for(int index = 0; index < this->size_unique_elements; index++) {
        resized_unique_elements[index] = this->unique_elements[index];
    }

    // make the linking
    delete[] this->unique_elements;

    this->unique_elements = resized_unique_elements;
}

void Bag::resize_positions() {
    this->capacity_positions = 2* this->capacity_positions;
    TElem* resized_positions = new TElem[this->capacity_positions];

    // copy the elements into the new dynamic array
    for(int index = 0; index < this->size_positions; index++) {
        resized_positions[index] = this->positions[index];
    }

    // make the linking
    delete[] this->positions;

    this->positions = resized_positions;
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

