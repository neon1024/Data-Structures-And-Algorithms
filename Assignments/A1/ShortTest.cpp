#include "ShortTest.h"
#include <cassert>
#include "Bag.h"
#include "BagIterator.h"
#include <iostream>

void testAll() { 
	Bag b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0);
	b.add(5);
	b.add(1);
	b.add(10);
    b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
    assert(b.nrOccurrences(15) == 0);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);
    assert(b.remove(1) == true);
    assert(b.nrOccurrences(1) == 0);
	BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}
    // TODO Bonus
    Bag c;
    assert(c.isEmpty() == true);
    assert(c.size() == 0);
    c.add(1);
    c.add(2);
    c.add(3);
    assert(c.isEmpty() == false);
    assert(c.size() == 3);
    c.add(1);
    c.add(2);
    assert(c.size() == 5);
    c.removeAllOccurrences(1);
    assert(c.size() == 3);
    assert(c.nrOccurrences(1) == 0);
    c.removeAllOccurrences(2);
    assert(c.size() == 1);
    assert(c.nrOccurrences(2) == 0);
    c.add(1);
    c.add(2);
    c.add(1);
    c.add(2);
    c.add(5);
    c.add(6);
    assert(c.size() == 7);
    c.removeAllOccurrences(1);
    assert(c.size() == 5);
    assert(c.nrOccurrences(1) == 0);
    c.remove(5);
    assert(c.size() == 4);
    assert(c.nrOccurrences(5) == 0);
    c.removeAllOccurrences(3);
    assert(c.size() == 3);
    assert(c.nrOccurrences(3) == 0);
    assert(c.nrOccurrences(2) == 2);
    assert(c.nrOccurrences(6) == 1);
}
