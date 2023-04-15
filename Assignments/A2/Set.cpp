#include "Set.h"
#include "SetITerator.h"

Set::Set() {
	//TODO - Implementation

    this->length = 0;
    this->capacity = 0;

    this->head = nullptr;
    this->tail = nullptr;
}

bool Set::add(TElem elem) {
	//TODO - Implementation
	return false;
}

bool Set::remove(TElem elem) {
	//TODO - Implementation
	return false;
}

bool Set::search(TElem elem) const {
	//TODO - Implementation
	return false;
}

int Set::size() const {
    return this->length;
}

bool Set::isEmpty() const {
    return this->length == 0;
}

Set::~Set() {
	//TODO - Implementation
}

SetIterator Set::iterator() const {
	return SetIterator(*this);
}
