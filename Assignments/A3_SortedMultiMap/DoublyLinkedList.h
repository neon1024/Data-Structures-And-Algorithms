#pragma once

struct DLLANode {
    ;
    int next;
    int prev;
};

class DoublyLinkedList {
private:
    DLLANode* nodes;
    int capacity;
    int length;
    int head;
    int tail;
    int first_free;

public:
    explicit DoublyLinkedList(int capacity);

    ~DoublyLinkedList();
};
