#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>
#include <algorithm>
#include <iostream>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& sorted_bag) : sorted_bag{sorted_bag} {
	this->relation = this->sorted_bag.relation;

    this->elements = new TComp[this->sorted_bag.size()];

    int position = 0;

    for(int i = 0; i < this->sorted_bag.capacity; ++i) {
        if(this->sorted_bag.elements[i] != NULL_TCOMP and this->sorted_bag.elements[i] != DELETED) {
            this->elements[position++] = this->sorted_bag.elements[i];
        }
    }

    // std::sort(this->elements, this->elements + this->sorted_bag.size(), [this](TComp& a, TComp& b){return this->relation(a, b);});

    this->merge_sort(0, this->sorted_bag.size() - 1);

    this->current_position = 0;
}

TComp SortedBagIterator::getCurrent() {
	if(! this->valid()) {
        throw std::exception();
    }

    return this->elements[this->current_position];
}

bool SortedBagIterator::valid() {
	return this->current_position < this->sorted_bag.size();
}

void SortedBagIterator::next() {
    if(! this->valid()) {
        throw std::exception();
    }

    this->current_position++;
}

void SortedBagIterator::first() {
    this->current_position = 0;
}

SortedBagIterator::~SortedBagIterator() {
    delete[] this->elements;
}

void SortedBagIterator::merge_sort(int left, int right) {
    if(left < right) {
        int mid = (left + right)/2;
        this->merge_sort(left, mid);
        this->merge_sort(mid + 1, right);
        this->merge(left, mid, right);
    }
}

void SortedBagIterator::merge(int left, int mid, int right) {
    int left_len = mid - left + 1;
    int right_len = right - mid;

    TComp* left_el = new TComp[left_len];
    TComp* right_el = new TComp[right_len];

    for(int i = 0; i < left_len; ++i) {
        left_el[i] = this->elements[left + i];
    }

    for(int j = 0; j < right_len; ++j) {
        right_el[j] = this->elements[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < left_len and j < right_len) {
        if(this->relation(left_el[i], right_el[j])) {
            this->elements[k++] = left_el[i++];
        } else {
            this->elements[k++] = right_el[j++];
        }
    }

    while(i < left_len) {
        this->elements[k++] = left_el[i++];
    }

    while(j < right_len) {
        this->elements[k++] = right_el[j++];
    }

    delete[] right_el;
    delete[] left_el;
}
