#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& sorted_bag;
	explicit SortedBagIterator(const SortedBag& sorted_bag);

    Relation relation;
	TComp* elements;
    int current_position;

    void merge_sort(int left, int right);
    void merge(int left, int mid, int right);

public:
    ~SortedBagIterator();
    void first();
    bool valid();
    TComp getCurrent();
    void next();
};
