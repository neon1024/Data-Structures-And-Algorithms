#pragma once

struct DLLANode {
    int data;
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

    void insert(int index, int data);
    void remove(int index);
    int get_element(int index) const;
    int size() const;
    bool empty() const;
};
