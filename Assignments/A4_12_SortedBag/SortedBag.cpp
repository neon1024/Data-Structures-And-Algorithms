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
/// Theta(capacity)

SortedBag::SortedBag(const SortedBag& sorted_bag) {
    this->number_of_elements = sorted_bag.number_of_elements;
    this->capacity = sorted_bag.capacity;
    this->relation = sorted_bag.relation;

    this->elements = new TComp[this->capacity];

    for(int i = 0; i < this->capacity; ++i) {
        this->elements[i] = sorted_bag.elements[i];
    }
}
/// Theta(capacity)

void SortedBag::add(TComp element) {
	int i = 0;
    int position = this->hash(element, i);

    while(i < this->capacity and this->elements[position] != NULL_TCOMP and this->elements[position] != DELETED) {
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
/// Best Case: Theta(1) \n
/// Average Case: Theta(capacity) \n
/// Worst Case: Theta(capacity) \n
/// Overall: O(capacity) \n

bool SortedBag::remove(TComp element) {
    int i = 0;
    int position = this->hash(element, i);

    while(i < this->capacity) {
        if(this->elements[position] == element) {
            this->elements[position] = DELETED;
            this->number_of_elements--;
            return true;
        }

        ++i;
        position = this->hash(element, i);
    }

    return false;
}
/// O(number_of_elements/capacity)

bool SortedBag::search(TComp element) const {
    int i = 0;
    int position = this->hash(element, i);

    while(i < this->capacity) {
        if(this->elements[position] == element) {
            return true;
        }

        ++i;
        position = this->hash(element, i);
    }

    return false;
}
/// O(number_of_elements/capacity)

int SortedBag::nrOccurrences(TComp element) const {
	int occurrences = 0;

    int i = 0;
    int position = this->hash(element, i);

    while(i < this->capacity) {
        if(this->elements[position] == element) {
            ++occurrences;
        }

        ++i;
        position = this->hash(element, i);
    }

	return occurrences;
}
/// Theta(capacity)

int SortedBag::size() const {
    return this->number_of_elements;
}
/// Theta(1)

bool SortedBag::isEmpty() const {
	return this->number_of_elements == 0;
}
/// Theta(1)

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
    return (this->hash1(abs(element)) + i * this->hash2(abs(element))) % this->capacity;
}
/// Theta(1)

int SortedBag::hash1(TComp element) const {
    /*
     * h1(k) = k % m
     * m: this->capacity, prime number
     * k: element, integer
     */
    return element % this->capacity;
}
/// Theta(1)

int SortedBag::hash2(TComp element) const {
    /*
     * h2(k) = 1 + k % (m - 1)
     * m: this->capacity, prime number
     * k: element, integer
     */
    return 1 + element % (this->capacity - 1);
}
/// Theta(1)

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
/// Theta(capacity)

void SortedBag::rehash_add(TComp* new_elements, TComp element) {
    int i = 0;
    int position = this->hash(element, i);

    while(i < this->capacity and new_elements[position] != NULL_TCOMP and new_elements[position] != DELETED) {
        ++i;
        position = this->hash(element, i);
    }

    new_elements[position] = element;
}
/// Theta(capacity)

void SortedBag::rehash() {
    // make a new dynamic array
    auto new_elements = new TComp[this->capacity];

    for(int i = 0; i < this->capacity; ++i) {
        new_elements[i] = NULL_TCOMP;
    }

    // traverse the original dynamic array, add each element from the original to the new one
    for(int i = 0; i < this->capacity; ++i) {
        if(this->elements[i] != NULL_TCOMP and this->elements[i] != DELETED) {
            this->rehash_add(new_elements, this->elements[i]);
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
/// Best Case: Theta(capacity) \n
/// Worst Case: Theta(capacity^2) \n
/// Overall: O(capacity^2) \n

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
/// Theta(sqrt(number))

int SortedBag::next_prime_number(int number) {
    while(! this->is_prime(number)) {
        ++number;
    }

    return number;
}
/// Theta(sqrt(number))

TComp SortedBag::leastFrequent() const {
    if(this->isEmpty()) {
        return NULL_TCOMP;
    }

    int minimum_occurrences = this->size();
    TComp target = NULL_TCOMP;

    for(int i = 0; i < this->capacity; ++i) {
        if(this->elements[i] != NULL_TCOMP and this->elements[i] != DELETED) {
            int occurrences = this->nrOccurrences(this->elements[i]);

            if(occurrences < minimum_occurrences) {
                minimum_occurrences = occurrences;
                target = this->elements[i];
            }
        }
    }

    return target;
}
/// Best Case: Theta(1) \n
/// Worst Case: Theta(capacity^2) \n
/// Overall: O(capacity^2) \n
