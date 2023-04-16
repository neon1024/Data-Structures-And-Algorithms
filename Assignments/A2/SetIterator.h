#pragma once
#include "Set.h"

class SetIterator {
	// DO NOT CHANGE THIS PART
	friend class Set;

private:
	// DO NOT CHANGE THIS PART
    Set set;

	SetIterator(const Set& s);

    int currentPosition;

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};
