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

    mt.modify(0, 0, 1);
    assert(mt.element(0, 0) == 1);

    mt.modify(0, 1, 1);
    assert(mt.element(0, 1) == 1);

    mt.modify(1, 0, 1);
    assert(mt.element(1, 0) == 1);

    Matrix mb1(5, 6);

    try {
        mb1.setMainDiagonal(10);

        assert(false);
    } catch(...) {
        assert(true);
    }

    Matrix mb2(5, 5);

    for(int index{0}; index < mb2.nrLines(); ++index) {
        std::cout << mb2.element(index, index) << '\n';
    }

    mb2.setMainDiagonal(10);

    for(int index{0}; index < mb2.nrLines(); ++index) {
        std::cout << mb2.element(index, index) << '\n';
    }
}
