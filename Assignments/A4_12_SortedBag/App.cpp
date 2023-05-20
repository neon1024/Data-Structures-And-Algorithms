#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

/*
 * 12. ADT SortedBag using a hashtable with open addressing (double  hashing) in which the elements are stored.
 * If an element appears multiple times, it will be stored multiple times in the  hashtable.
 * In the constructor of the iterator create a sorted array of the elements and use that array for iterating.
 */

int main() {
    std::cout << "Short testing..." << '\n';

	testAll();

    std::cout << "Short testing done!" << '\n';

    std::cout << "Extended testing..." << '\n';

	testAllExtended();

    std::cout << "Extended testing done!" << '\n';
}
