#include <cassert>

#include "SortedMultiMap.h"
#include "SMMIterator.h"
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
}
