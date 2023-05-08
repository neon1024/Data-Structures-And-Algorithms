#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

int main(){
    /*
     * 20. ADT SortedMultiMap: using a DLLA with unique keys ordered based on a relation on the keys.
     * Every key will be associated with a DLLA of the values belonging to that key.
     */

    std::cout << "Starting SMM Tests..." << '\n';

    testAll();
	testAllExtended();

    std::cout<<"Finished SMM Tests!"<<std::endl;

    return 0;
}
