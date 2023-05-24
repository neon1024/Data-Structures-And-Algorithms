#include "ShortTest.h"
#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <assert.h>
#include <iostream>

bool relation1(TComp e1, TComp e2) {
	return e1 <= e2;
}

void testAll() {
	SortedBag sb(relation1);
	sb.add(5);
	sb.add(6);
	sb.add(0);
	sb.add(5);
	sb.add(10);
	sb.add(8);

	assert(sb.size() == 6);

	assert(sb.nrOccurrences(5) == 2);

	assert(sb.remove(5) == true);
	assert(sb.size() == 5);

	assert(sb.search(6) == true);
	assert(sb.isEmpty() == false);

	SortedBagIterator it = sb.iterator();
	assert(it.valid() == true);
	while (it.valid()) {
		it.next();
	}
	assert(it.valid() == false);
	it.first();
	assert(it.valid() == true);

    // Bonus
    SortedBag bonus_sb(relation1);

    bonus_sb.add(0);
    bonus_sb.add(5);
    bonus_sb.add(3);
    bonus_sb.add(10);
    bonus_sb.add(5);
    bonus_sb.add(0);
    bonus_sb.add(3);
    bonus_sb.add(11);
    bonus_sb.add(12);

    SortedBagIterator bonus_it = bonus_sb.iterator();

    while(bonus_it.valid()) {
        std::cout << bonus_it.getCurrent() << '\n';
        bonus_it.next();
    }

    std::cout << "least frequent: " << bonus_sb.leastFrequent() << '\n';
}
