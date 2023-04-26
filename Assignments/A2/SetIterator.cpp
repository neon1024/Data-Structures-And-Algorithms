#include "SetIterator.h"
#include "Set.h"
#include <exception>

SetIterator::SetIterator(const Set& m) : set(m) {
     // this->currentPosition = 0;
     this->currentNode = reinterpret_cast<Node *>(this->set.head);
}

void SetIterator::first() {
    // this->currentPosition = 0;
    this->currentNode = reinterpret_cast<Node *>(this->set.head);
}

void SetIterator::next() {
    if(!this->valid()) {
        throw std::exception();
    }

    // this->currentPosition++;
    this->currentNode = this->currentNode->next;
}

TElem SetIterator::getCurrent() {
    // Time Complexity:
    // Best Case: Theta(1)
    // Average Case: Theta(1)
    // Worst Case: Theta(1)
    // Overall: Theta(1)

    if(!this->valid()) {
        throw std::exception();
    }

//    return this->set.getElementAt(this->currentPosition);

    return this->currentNode->element;
}

bool SetIterator::valid() const {
    //return this->currentPosition < this->set.size();
    return this->currentNode != nullptr;
}

void SetIterator::jumpForward(int k) {
    // Time Complexity:
    // Best Case: Theta(1)
    // Average Case: Theta(k)
    // Worst Case: Theta(k)
    // Overall: O(k)

    if(! this->valid()) {
        throw std::exception();
    }

    if(k <= 0) {
        throw std::exception();
    }

    // this->currentPosition+=k;

    for(int i = 0; i < k; ++i) {
        this->currentNode = this->currentNode->next;
    }
}
