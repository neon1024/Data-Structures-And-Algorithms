#include <cassert>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include "../ValueIterator/ValueIterator.h"
#include <exception>
#include <vector>
#include <iostream>

using namespace std;

bool relation1(TKey key1, TKey key2) {
	return key1 <= key2;
}

void testAll(){
	SortedMultiMap smm = SortedMultiMap(relation1);

	assert(smm.size() == 0);
	assert(smm.isEmpty());

    smm.add(1,2);
    smm.add(1,3);

    assert(smm.size() == 2);
    assert(!smm.isEmpty());

    vector<TValue> v= smm.search(1);

    assert(v.size()==2);
    v= smm.search(3);
    assert(v.empty());

    SMMIterator it = smm.iterator();

    it.first();

    while (it.valid()){
    	TElem e = it.getCurrent();
    	it.next();
    }

    // Bonus
    SortedMultiMap smm1 = SortedMultiMap{relation1};

    smm1.add(1, 1);
    smm1.add(1, 2);
    smm1.add(1, 3);
    smm1.add(2, 10);
    smm1.add(1, 4);
    smm1.add(1, 5);
    smm1.add(3, 11);

    ValueIterator vi1 = smm1.iterator(1);

    vi1.first();

    while(vi1.valid()) {
        TValue v1 = vi1.getCurrent();

        std::cout << v1 << ' ';

        vi1.next();
    }

    ValueIterator vi2 = smm1.iterator(0);

    try {
        vi2.next();

        assert(false);
    } catch(...) {
        assert(true);
    }
}
