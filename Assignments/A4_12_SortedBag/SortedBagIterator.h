#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& sorted_bag;
	explicit SortedBagIterator(const SortedBag& sorted_bag);

	// TODO - Representation

public:
    void first();
    bool valid();
    TComp getCurrent();
    void next();
};
