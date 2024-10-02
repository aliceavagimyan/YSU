#include <iostream>
#include "list.hpp"

int main(){
    DoublyList<int> list;
    list.push_front(10);
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    list.push_front(40);

    std::cout<<"List before:"<<std::endl;
    list.print();

    list.remove_all(10);

    std::cout<<"List after:"<<std::endl;
    list.print();

return 0;

}