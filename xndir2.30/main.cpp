#include <iostream>
#include "vector.hpp"

int main() {
    Vector<int> vec = {1, 2, 3, 4, 5}; 
    int target1 = 3;
    int index1 = vec.binarySearch(target1);
    if (index1 != -1) {
        std::cout << "Element " << target1 << " found at index: " << index1 << std::endl;
    } else {
        std::cout << "Element " << target1 << " not found in vector." << std::endl;
    }

    int target2 = 6;
    int index2 = vec.binarySearch(target2);
    if (index2 != -1) {
        std::cout << "Element " << target2 << " found at index: " << index2 << std::endl;
    } else {
        std::cout << "Element " << target2 << " not found in vector." << std::endl;
    }

    return 0;
}
