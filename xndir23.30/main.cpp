#include "list.hpp"

int main() {
    CyclicList clist;

   
    clist.append(1);
    clist.append(2);
    clist.append(3);
    clist.append(4);
    clist.append(5);

    std::cout << "List  ";
    clist.print();

    
    clist.reverse();

    std::cout << "list after ";
    clist.print();

    return 0;
}
