#include <iostream>
#include "list.hpp"

int main() {
    DoublyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    std::cout << "list: ";
    list.print(); 

    std::cout << "elements with iterators ";
    for (DoublyList<int>::Iterator it = list.begin(); !it.is_end() ; ++it) {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;

    
    DoublyList<int>::Iterator it=list.begin();
    std::cout << "is begin ?: "  << std::boolalpha <<it.is_begin() << std::endl; 
    ++it; 
    std::cout << "is begin after increment(prefix)?:" << std::boolalpha << it.is_begin() << std::endl; 
    it = list.end(); 
    std::cout << "is end ? :" <<std::boolalpha << it.is_end() << std::endl; 

    return 0;
}
