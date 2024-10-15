#include <iostream>
#include "list.hpp"

int main() {
    DoublyList<int> list;
    list.push_back(4);
    list.push_back(1);
    list.push_back(3);
    list.push_back(5);
    list.push_back(2);

    std::cout << "list before sort: ";
    list.print();

    list.bubble_sort();

    std::cout << "sorted list: ";
    list.print();

    return 0;
}
