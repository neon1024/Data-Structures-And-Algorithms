#include "SetIterator.h"
#include "Set.h"
#include <exception>
#include <iostream>

SetIterator::SetIterator(const Set& m) : set(m) {
    this->currentPosition = 0;
}

void SetIterator::first() {
    this->currentPosition = 0;
}

void SetIterator::next() {
    if(!this->valid()) {
        throw std::exception();
    }

    this->currentPosition++;
}

TElem SetIterator::getCurrent() {
    if(!this->valid()) {
        throw std::exception();
    }

    return this->set.getElementAt(this->currentPosition);
}

bool SetIterator::valid() const {
    return this->currentPosition < this->set.size();
}
