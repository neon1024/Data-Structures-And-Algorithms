#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(int capacity) {
    this->capacity = capacity;
    this->nodes = new DLLANode[this->capacity];
    this->length = 0;
    this->head = -1;
    this->tail = -1;
    this->first_free = 0;

    for(int i = 0; i < capacity - 1; ++i) {
        this->nodes[i].next = i + 1;
        this->nodes[i].prev = i - 1;
    }

    this->nodes[capacity - 1].next = -1;
}

DoublyLinkedList::~DoublyLinkedList() {
    delete[] this->nodes;
}

void DoublyLinkedList::insert(int index, int data) {

}

void DoublyLinkedList::remove(int index) {

}

int DoublyLinkedList::get_element(int index) const {

}

int DoublyLinkedList::size() const {
    return this->length;
}

bool DoublyLinkedList::empty() const {
    return this->length == 0;
}
