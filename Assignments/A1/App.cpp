#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main() {

	testAll();

    cout << "Short tests over" << '\n';

	testAllExtended();

	cout << "All tests over" << '\n';
}
