#include <iostream>


extern "C" void function_from_CPP() {
    std::cout << "This is a function from C++." << std::endl;
}