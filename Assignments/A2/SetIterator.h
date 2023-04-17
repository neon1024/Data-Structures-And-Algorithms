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
};
