#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

int main(){
    std::cout << "Starting SMM Tests..." << '\n';

    testAll();
	testAllExtended();

    std::cout<<"Finished SMM Tests!"<< '\n';

    system("pause");
}
