#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>

SortedBag::SortedBag(Relation r, int capacity) {
	this->relation = r;
    this->capacity = capacity;
    this->number_of_elements = 0;

    this->elements = new TComp[this->capacity];

    for(int i = 0; i < this->capacity; ++i) {
        this->elements[i] = NULL_TCOMP;
    }
}

SortedBag::SortedBag(const SortedBag& sorted_bag) {
    this->number_of_elements = sorted_bag.number_of_elements;
    this->capacity = sorted_bag.capacity;
    this->relation = sorted_bag.relation;

    this->elements = new TComp[this->capacity];

    for(int i = 0; i < this->capacity; ++i) {
        this->elements[i] = sorted_bag.elements[i];
    }
}

void SortedBag::add(TComp element) {
	int i = 0;
    int position = this->hash(element, i);

    while(i < this->capacity and this->elements[position] != NULL_TCOMP) {
        ++i;
        position = this->hash(element, i);
    }

    if(i == this->capacity) {
        this->resize();
        this->rehash();
        this->add(element);
    }
    else {
        this->elements[position] = element;
        this->number_of_elements++;
    }
}

bool SortedBag::remove(TComp element) {
	int current_position = 0;

    while(current_position < this->capacity and this->elements[current_position] != element) {
        ++current_position;
    }

    if(current_position == this->capacity) {
        return false;
    }

    this->elements[current_position] = DELETED;
    this->number_of_elements--;

    return true;
}

bool SortedBag::search(TComp element) const {
    for(int i = 0; i < this->capacity; ++i) {
        if(this->elements[i] == element) {
            return true;
        }
    }

    return false;
}

int SortedBag::nrOccurrences(TComp element) const {
	int occurrences = 0;

    for(int i = 0; i < this->capacity; ++i) {
        if(this->elements[i] == element) {
            ++occurrences;
        }
    }

	return occurrences;
}

int SortedBag::size() const {
    return this->number_of_elements;
}

bool SortedBag::isEmpty() const {
	return this->number_of_elements == 0;
}

SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}

SortedBag::~SortedBag() {
	delete[] this->elements;
}

int SortedBag::hash(TComp element, int i) const {
    /*
     * h(k,i) = (h1(k) + i*h2(k)) % m
     * m: this->capacity, prime number
     * k: element, integer
     * i: i, permutation
     */
    return (this->hash1(element) + i * this->hash2(element)) % this->capacity;
}

int SortedBag::hash1(TComp element) const {
    /*
     * h1(k) = k % m
     * m: this->capacity, prime number
     * k: element, integer
     */
    return element % this->capacity;
}

int SortedBag::hash2(TComp element) const {
    /*
     * h2(k) = 1 + k % (m - 1)
     * m: this->capacity, prime number
     * k: element, integer
     */
    return 1 + element % (this->capacity - 1);
}

void SortedBag::resize() {
    int new_capacity = this->next_prime_number(2 * this->capacity);

    auto new_elements = new TComp[new_capacity];

    for(int i = 0; i < this->capacity; ++i) {
        new_elements[i] = this->elements[i];
    }

    for(int i = this->capacity; i < new_capacity; ++i) {
        new_elements[i] = NULL_TCOMP;
    }

    delete[] this->elements;
    this->capacity = new_capacity;
    this->elements = new_elements;
}

void SortedBag::add_rehash(TComp* new_elements, TComp element) {
    int i = 0;
    int position = this->hash(element, i);

    while(i < this->capacity and new_elements[i] != NULL_TCOMP) {
        ++i;
        position = this->hash(element, i);
    }

    new_elements[position] = element;
}

void SortedBag::rehash() {
    // make a new dynamic array
    auto new_elements = new TComp[this->capacity];

    for(int i = 0; i < this->capacity; ++i) {
        new_elements[i] = NULL_TCOMP;
    }

    // traverse the original dynamic array, add each element from the original to the new one
    for(int i = 0; i < this->capacity; ++i) {
        if(this->elements[i] != NULL_TCOMP and this->elements[i] != DELETED) {
            this->add_rehash(new_elements, this->elements[i]);
        }
        else {
            if(this->elements[i] == DELETED) {
                new_elements[i] = DELETED;
            }
        }
    }

    // destroy the old dynamic array and link the new dynamic array
    delete[] this->elements;
    this->elements = new_elements;
}

bool SortedBag::is_prime(int number) {
    if(number < 2) {
        return false;
    }

    for(int d = 2; d*d <= number; ++d) {
        if(number % d == 0) {
            return false;
        }
    }

    return true;
}

int SortedBag::next_prime_number(int number) {
    while(! this->is_prime(number)) {
        ++number;
    }

    return number;
}
