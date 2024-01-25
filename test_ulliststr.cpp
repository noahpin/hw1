#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;

    int numItems = 50;
    for(int i = 0; i < numItems; i++) {
        list.push_back("asdf");
    }
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "Empty: " << list.empty() << std::endl;
    std::cout << "commence: " << std::endl;
    
    for(int i = 0; i < numItems; i++) {
        std::cout << "Size: " << list.size() << std::endl;
        list.pop_front();
        std::cout << "Size: " << list.size() << std::endl;
        std::cout << "Empty: " << list.empty() << std::endl;
        std::cout << "--------" << std::endl;
    }
}
