#include "Set.h"
#include "SetITerator.h"

Set::Set() {
	//TODO - Implementation

    this->length = 0;
    this->capacity = 0;

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
    if(this->head == nullptr) {
        Node *node = new Node;
        node->element = element;
        this->head = node;
        this->tail = node;
        node->next = nullptr;
        return true;
    }

    if(this->search(element) == false) {
        Node* node = new Node;
        node->element = element;
        this->tail->next = node;
        this->tail = node;
        return true;
    }

	return false;
}

bool Set::remove(TElem element) {
	//TODO - Implementation
    Node* currentNode = this->head->next;
    Node* previousNode = this->head;

    if(previousNode and previousNode->element == element) {
        delete previousNode;
        this->head = nullptr;

        return true;
    }

    while(currentNode != nullptr) {
        if(currentNode->element == element) {
            previousNode->next = currentNode->next;
            delete currentNode;

            return true;
        }

        currentNode = currentNode->next;
        previousNode = previousNode->next;
    }

	return false;
}

bool Set::search(TElem element) const {
	Node* currentNode = this->head;

    while(currentNode != nullptr) {
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
	//TODO - Implementation
}

SetIterator Set::iterator() const {
	return SetIterator(*this);
}
