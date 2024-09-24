#include <iostream>
#include "list.hpp" 

int main() {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(2);
    myList.push_back(3);
     myList.push_back(3);
      myList.push_back(3);
  std::cout << "Before removing duplicates:" << std::endl;
     myList.print();

    myList.removeDuplicates();

    std::cout << "After removing duplicates:" << std::endl;
    myList.print(); 

    return 0;
}
