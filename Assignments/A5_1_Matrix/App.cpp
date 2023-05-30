
#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

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
