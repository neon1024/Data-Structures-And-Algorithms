#include <exception>
#include "BagIterator.h"
#include "Bag.h"

BagIterator::BagIterator(const Bag& c): bag(c)  // this->bag = c
{
    this->current_position = 0;
}

void BagIterator::first() {
    this->current_position = 0;
}

void BagIterator::next() {
    if(valid()) {
        this->current_position++;
    } else {
        throw std::exception();
    }
}

bool BagIterator::valid() const {
    return this->current_position < bag.size();
}

TElem BagIterator::getCurrent() const {
    if(valid()) {
        return bag.unique_elements[bag.positions[this->current_position]];
    }
	throw std::exception();
}
