#include <exception>
#include "BagIterator.h"
#include "Bag.h"

BagIterator::BagIterator(const Bag& c): bag(c)  // this->bag = c
{
	//TODO - Implementation
    this->current_position = 0;
}

void BagIterator::first() {
	//TODO - Implementation
    this->current_position = 0;
}

void BagIterator::next() {
	//TODO - Implementation
    if(valid()) {
        this->current_position++;
    }
}

bool BagIterator::valid() const {
	//TODO - Implementation
    if(this->current_position < bag.size()) {
        return true;
    }
	return false;
}

TElem BagIterator::getCurrent() const {
	//TODO - Implementation
    if(valid()) {
        return bag.unique_elements[bag.positions[this->current_position]];
    }
	return NULL_TELEM 
}
