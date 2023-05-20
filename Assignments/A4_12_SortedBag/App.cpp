#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main() {
    std::cout << "Short testing..." << '\n';

	testAll();

    std::cout << "Short testing done!" << '\n';

    std::cout << "Extended testing..." << '\n';

	testAllExtended();

    std::cout << "Extended testing done!" << '\n';
}
