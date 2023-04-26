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
    // Time Complexity:
    // Best Case: Theta(1)
    // Average Case: Theta(n)
    // Worst Case: Theta(n)
    // Overall: O(n)

    if(!this->valid()) {
        throw std::exception();
    }

    return this->set.getElementAt(this->currentPosition);
}

bool SetIterator::valid() const {
    return this->currentPosition < this->set.size();
}

void SetIterator::jumpForward(int k) {
    if(! this->valid()) {
        throw std::exception();
    }

    if(k <= 0) {
        throw std::exception();
    }

    this->currentPosition+=k;
}
