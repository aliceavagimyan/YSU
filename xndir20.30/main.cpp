#include <iostream>
#include "list.hpp"
int main() {
    DoublyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.print(); 

    auto* node = new DoublyList<int>::Node<int>(1);
    list.insert_after(list.head, 6);
    list.print(); 

   DoublyList<int>::Node<int>* node_to_delete = list.head->pNext; 
    list.delete_node(node_to_delete);
    list.print(); 

    return 0;
}
