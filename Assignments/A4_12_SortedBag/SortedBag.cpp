#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
	//TODO - Implementation
}

void SortedBag::add(TComp e) {
	//TODO - Implementation
}


bool SortedBag::remove(TComp e) {
	//TODO - Implementation
	return false;
}


bool SortedBag::search(TComp elem) const {
	//TODO - Implementation
	return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
	//TODO - Implementation
	return 0;
}



int SortedBag::size() const {
	//TODO - Implementation
	return 0;
}


bool SortedBag::isEmpty() const {
	//TODO - Implementation
	return false;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	//TODO - Implementation
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
