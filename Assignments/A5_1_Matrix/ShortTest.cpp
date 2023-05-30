#include <assert.h>
#include "Matrix.h"
#include <iostream>

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);

    Matrix mt(8, 8);

    assert(mt.nrLines() == 8);
    assert(mt.nrColumns() == 8);
    assert(mt.element(0, 0) == NULL_TELEM);
    assert(mt.element(0, 1) == NULL_TELEM);
    assert(mt.element(1, 0) == NULL_TELEM);
    assert(mt.element(1, 1) == NULL_TELEM);

    mt.modify(0, 0, 1);
    assert(mt.element(0, 0) == 1);

    mt.modify(1, 1, 1);
    assert(mt.element(1, 1) == 1);

    mt.modify(2, 3, 1);
    assert(mt.element(2, 3) == 1);
}
