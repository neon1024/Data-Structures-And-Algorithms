#include "Set.h"
#include "SetITerator.h"
#include <iostream>
Set::Set() {
    this->length = 0;

    this->head = nullptr;
    this->tail = nullptr;
}

const TElem Set::getElementAt(int position) {
    Node* currentNode = this->head;

    int currentPosition = 0;

    while(currentPosition != position and currentNode) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    return currentNode->element;
}

bool Set::add(TElem element) {
    if(!this->search(element)) {
        Node* node = new Node;
        node->element = element;
        node->next = nullptr;

        if(this->head == nullptr) {
            this->head = node;
            this->head->next = this->tail;
            this->tail = node;
            this->tail->next = nullptr;

            this->length++;

            return true;
        }

        this->tail->next = node;
        this->tail = node;

        this->length++;

        return true;
    }

    return false;
}

bool Set::remove(TElem element) {
    Node* currentNode = this->head;
    Node* previousNode = this->head;
    bool removed{false};

    if(this->head == nullptr) {
        return false;
    }

    currentNode = currentNode->next;

    while(currentNode) {
        if(currentNode->element == element) {
            Node* deletedNode = currentNode;
            previousNode->next = currentNode->next;
            currentNode = currentNode->next;
            delete deletedNode;
            this->length--;
            removed = true;
        } else {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    if(this->head->element == element) {
        Node* deletedNode = head;
        this->head = this->head->next;
        delete deletedNode;
        this->length--;
        removed = true;
    }

    return removed;
}

bool Set::search(TElem element) const {
	Node* currentNode = this->head;

    while(currentNode) {
        if(currentNode->element == element) {
            return true;
        }
        currentNode = currentNode->next;
    }

    return false;
}

int Set::size() const {
    return this->length;
}

bool Set::isEmpty() const {
    return this->length == 0;
}

Set::~Set() {
	// TODO - Implementation
//    while(this->head) {
//        Node* deletedNode = this->head;
//        this->head = this->head->next;
//        delete deletedNode;
//    }
}

SetIterator Set::iterator() const {
	return SetIterator(*this);
}
