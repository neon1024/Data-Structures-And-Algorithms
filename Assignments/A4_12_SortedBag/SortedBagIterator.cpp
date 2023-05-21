#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <algorithm>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& sorted_bag) : sorted_bag{sorted_bag} {
	this->relation = this->sorted_bag.relation;

    this->elements = new TComp[this->sorted_bag.size()];

    int position = 0;

    for(int i = 0; i < this->sorted_bag.capacity; ++i) {
        if(this->sorted_bag.elements[i] != NULL_TCOMP and this->sorted_bag.elements[i] != DELETED) {
            this->elements[position++] = this->sorted_bag.elements[i];
        }
    }

    std::sort(this->elements, this->elements + this->sorted_bag.size(), [this](TComp& a, TComp& b){return this->relation(a, b);});

    this->current_position = 0;
}

TComp SortedBagIterator::getCurrent() {
	if(! this->valid()) {
        throw std::exception();
    }

    return this->elements[this->current_position];
}

bool SortedBagIterator::valid() {
	return this->current_position < this->sorted_bag.size();
}

void SortedBagIterator::next() {
    if(! this->valid()) {
        throw std::exception();
    }

    this->current_position++;
}

void SortedBagIterator::first() {
    this->current_position = 0;
}

SortedBagIterator::~SortedBagIterator() {
    delete[] this->elements;
}
