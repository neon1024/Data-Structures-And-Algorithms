#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r, int capacity) {
	this->relation = r;
    this->capacity = capacity;
    this->number_of_elements = 0;

    this->elements = new TComp[this->capacity];
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
    } else {
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
    int current_position = 0;
    while(current_position < this->capacity and this->elements[element] != element) {
        ++current_position;
    }

    return current_position != this->capacity;
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
