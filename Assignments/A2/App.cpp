#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stack>
#include <iostream>
using namespace std;

int main() {
    std::cout << "Short testing..." << '\n';

    testAll();

    std::cout << "Short testing done!" << '\n';

    std::cout << "Extended testing..." << '\n';

	testAllExtended();

    std::cout << "Extended testing done!" << '\n';

    return 0;
}
