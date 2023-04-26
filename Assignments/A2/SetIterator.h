#pragma once
#include "Set.h"

class SetIterator {
	// DO NOT CHANGE THIS PART
	friend class Set;

private:
	// DO NOT CHANGE THIS PART
    Set set;

    int currentPosition;

public:
    SetIterator(const Set& s);
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
    // Bonus
    // moves the current element from the iterator k steps forward,
    // or makes the iterator invalid if there are less than k elements left in the Set.
    // throws an exception if the iterator is invalid or if k is negative or zero.
    void jumpForward(int k);
};
