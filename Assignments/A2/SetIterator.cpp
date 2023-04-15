#include "SetIterator.h"
#include "Set.h"


SetIterator::SetIterator(const Set& m) : set(m) {
    this->currentPosition = 0;
}

void SetIterator::first() {
    this->currentPosition = 0;
}

void SetIterator::next() {
    this->currentPosition++;
}

TElem SetIterator::getCurrent() {
	// TODO - Implementation
    if(this->valid()) {
        return this->set.getElementAt(this->currentPosition);
    }

	return NULL_TELEM;
}

bool SetIterator::valid() const {
    return this->currentPosition < this->set.size();
}
