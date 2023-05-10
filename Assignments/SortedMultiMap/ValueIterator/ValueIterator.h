#pragma once

#include "SortedMultiMap.h"

class ValueIterator {
    const SortedMultiMap& smm;
    TKey key;
    int current_position;
    int first_position;

public:
    ValueIterator(const SortedMultiMap& smm, TKey key);

    void first();
    void next();
    bool valid() const;
    TValue getCurrent() const;
};
