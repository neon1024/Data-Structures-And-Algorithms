#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
    this->relation = r;
    this->capacity = 10;
    this->DLLANodes = new DLLNode[this->capacity];
    this->length = 0;
    this->head = -1;
    this->tail = -1;
    this->firstEmpty = 0;
    this->DLLANodes[firstEmpty].prev = -1;
    this->DLLANodes[firstEmpty].next = 1;
    this->DLLANodes[firstEmpty].info = NULL_TELEM;
    ///We set the previous and the next for the first empty position
    ///After that we set the links between the other nodes from the array, starting from the second node until the last but one
    for (int i = 1; i < this->capacity - 1; i++)
    {
        ///We establish the position path for the rest of the nodes
        this->DLLANodes[i].next = i + 1;
        this->DLLANodes[i].prev = i - 1;
        this->DLLANodes[i].info = NULL_TELEM;
    }
    this->DLLANodes[this->capacity - 1].next = -1;
    this->DLLANodes[this->capacity - 1].prev = this->capacity - 2;
    this->DLLANodes[this->capacity - 1].info = NULL_TELEM;
}
/// Theta(capacity)

vector<TValue> SortedMultiMap::removeKey(TKey key) {
    vector<TValue> values;
    int CurrentElement = this->head;
    int SecondCurrentElement;
    while(CurrentElement != -1){
        if(this->relation(this->DLLANodes[CurrentElement].info.first, key))
        {
                if (this->DLLANodes[CurrentElement].info.first == key) {
                    values.push_back(this->DLLANodes[CurrentElement].info.second);
                    SecondCurrentElement = this->DLLANodes[CurrentElement].next;
                    this->remove(key, this->DLLANodes[CurrentElement].info.second);
                    CurrentElement = SecondCurrentElement;
                }
                else
                    CurrentElement = this->DLLANodes[CurrentElement].next;
        }
        else
            break;
    }
    return values;
}
///Best Case: Theta(1)
///Worst Case: Theta((this->length)^2)
///Total Complexity: O((this->length)^2)

void SortedMultiMap::add(TKey key, TValue value) {
    // check if we reached the maximum capacity, and in this case we do a resize
    if(this->length == this->capacity)
        this->resize();

    // case 1: the list is empty
    if(this->length == 0 && this->head == -1) {
        this->head = this->firstEmpty;
        this->length++;

        this->firstEmpty = this->DLLANodes[this->firstEmpty].next;

        if(this->firstEmpty != -1)
            this->DLLANodes[this->firstEmpty].prev = -1;

        this->DLLANodes[this->head].info.first = key;
        this->DLLANodes[this->head].info.second = value;

        this->DLLANodes[this->head].next = -1;
        this->tail = this->head;

        return;
    }

    /// case 2: the element has to be placed in front of the head
    if(this->relation(key, this->DLLANodes[this->head].info.first)) {
        int new_head = this->firstEmpty;
        this->length++;

        this->firstEmpty = this->DLLANodes[this->firstEmpty].next;

        if(this->firstEmpty != -1)
            this->DLLANodes[this->firstEmpty].prev = -1;

        this->DLLANodes[new_head].next = this->head; /// make the new node become the head, the next node from the new node will be the head
        this->DLLANodes[new_head].prev = -1;

        this->DLLANodes[new_head].info.first = key;
        this->DLLANodes[new_head].info.second = value;

        this->DLLANodes[this->head].prev = new_head; /// the previous node from the initial head will become the new node we just added, which became the head
        this->head = new_head;

        return;
    }

    /// case 3: the element has to be placed after the tail
    int CurrentElement = this->head;

    while(this->DLLANodes[CurrentElement].next != -1 && !this->relation(key, this->DLLANodes[this->DLLANodes[CurrentElement].next].info.first)) {
        CurrentElement = this->DLLANodes[CurrentElement].next;
    }

    if(this->DLLANodes[CurrentElement].next == -1) {
        this->length++;
        int new_element = this->firstEmpty;

        this->firstEmpty = this->DLLANodes[this->firstEmpty].next;
        if(this->firstEmpty != -1)
            this->DLLANodes[this->firstEmpty].prev = -1;

        this->DLLANodes[this->tail].next = new_element;
        int old_tail = this->tail;
        this->tail = new_element;
        this->DLLANodes[this->tail].next = -1;
        this->DLLANodes[this->tail].prev = old_tail;

        this->DLLANodes[this->tail].info.first = key;
        this->DLLANodes[this->tail].info.second = value;

        return;
    }

    /// case 4: the element has to be placed between two nodes
    if(this->DLLANodes[CurrentElement].next != -1 && this->relation(key, this->DLLANodes[this->DLLANodes[CurrentElement].next].info.first)) {
        this->length++;
        int new_element = this->firstEmpty;

        this->firstEmpty = this->DLLANodes[this->firstEmpty].next;
        if(this->firstEmpty != -1)
            this->DLLANodes[this->firstEmpty].prev = -1;

        int NextElement = this->DLLANodes[CurrentElement].next;
        int PreviousElement = CurrentElement;
        DLLANodes[PreviousElement].next = new_element;

        DLLANodes[new_element].next = NextElement;
        DLLANodes[new_element].prev = PreviousElement;

        DLLANodes[new_element].info.first = key;
        DLLANodes[new_element].info.second = value;

        DLLANodes[NextElement].prev = new_element;
    }
}
///Best case: Theta(1)
///Worst case: Theta(this->length)
///Average Case: O(this->length) => Total complexity: O(this->length)

vector<TValue> SortedMultiMap::search(TKey c) const {
    vector<TValue> values;
	int CurrentElement = this->head;
	while(CurrentElement != -1){
	    if(this->relation(this->DLLANodes[CurrentElement].info.first, c))
        {
	        if(this->DLLANodes[CurrentElement].info.first == c)
            {
                values.push_back(this->DLLANodes[CurrentElement].info.second);
            }
            CurrentElement = this->DLLANodes[CurrentElement].next;
	    }
	    else
	        break;
	}
	return values;
}
///Best case: Theta(1)
///Worst case: Theta(this->length)
///Average Case: O(this->length) => Total complexity: O(this->length)

bool SortedMultiMap::remove(TKey key, TValue value) {
	int current_element = this->head;

	while(current_element != -1) {
	    if(this->DLLANodes[current_element].info.first == key and this->DLLANodes[current_element].info.second == value) {
	        this->DLLANodes[current_element].info = NULL_TELEM;
	        this->length--;

	        /// remove the element from the list
	        /// case 1: the list has only 1 element
	        if(current_element == this->head && current_element == this->tail)
            {
	            this->head = -1;
	            this->tail = -1;
            }
	        ///Case 2: It means the element we have to remove is the head
	        else if(current_element == this->head)
            {
	            this->head = this->DLLANodes[this->head].next;
	            this->DLLANodes[this->head].prev = -1;
            }
	        ///Case 3: It means the element we have to remove is the tail
	        else if(current_element == this->tail)
            {
	            this->tail = this->DLLANodes[this->tail].prev;
	            this->DLLANodes[this->tail].next = -1;
            }
	        ///Case 4: It means the element we have to remove is somewhere between the head and the tail
	        else {
                int PreviousElement = this->DLLANodes[current_element].prev;
                int NextElement = this->DLLANodes[current_element].next;
                this->DLLANodes[PreviousElement].next = NextElement;
                this->DLLANodes[NextElement].prev = PreviousElement;
            }
	        /// free the position of the deleted node
	        free(current_element);
	        return true;
        }
	    else
            current_element = this->DLLANodes[current_element].next;

    }
    return false;
}
/// Best case: Theta(1)
/// Average Case: O(length)
/// Worst case: Theta(length)
/// Total complexity: O(length)

int SortedMultiMap::size() const {
    return this->length;
}
///Theta(1)

bool SortedMultiMap::isEmpty() const {
	if(this->length == 0)
	    return true;
	return false;
}
///Theta(1)

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator{*this};
}
///Theta(1)

SortedMultiMap::~SortedMultiMap() {
	delete[] this->DLLANodes;
}
///Theta(1)

void SortedMultiMap::resize() {
    this->capacity = 2 * this->capacity;
    auto* resized_array = new DLLNode[this->capacity];

    for(int i = 0; i < this->length; ++i)
        resized_array[i] = this->DLLANodes[i];

    this->firstEmpty = this->length;
    resized_array[firstEmpty].prev = -1;
    resized_array[firstEmpty].next = this->length + 1;
    resized_array[firstEmpty].info = NULL_TELEM;

    for(int i=this->length + 1; i<this->capacity -1; i++) {
        resized_array[i].prev = i - 1;
        resized_array[i].next = i + 1;
        resized_array[i].info = NULL_TELEM;
    }

    resized_array[this->capacity - 1].prev = this->capacity - 2;
    resized_array[this->capacity - 1].next = -1;
    resized_array[this->capacity - 1].info = NULL_TELEM;

    delete[] this->DLLANodes;
    this->DLLANodes = resized_array;
}
///Theta(capacity) We have two loops, one which go from 0 to capacity/2 and the other one which goes from capacity/2 until capacity

int SortedMultiMap::allocate() {
    int newElem = this->firstEmpty;
    if (newElem != -1) {
        this->firstEmpty = this->DLLANodes[this->firstEmpty].next;
        if(this->firstEmpty != -1)
            this->DLLANodes[this->firstEmpty].prev = -1;
        this->DLLANodes[newElem].next = -1;
        this->DLLANodes[newElem].prev = -1;
    }
    return newElem;
}
///Theta(1)

void SortedMultiMap::free(int position) {
    this->DLLANodes[position].next = this->firstEmpty;
    this->DLLANodes[position].prev = -1;
    this->DLLANodes[this->firstEmpty].prev = position;
    this->firstEmpty = position;
}
///Theta(1)
