#include "bst.hpp"
#include <iostream>

int main(){
    BST<int> tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(0);
    tree.insert(2);
    tree.insert(6);
    tree.insert(0);
    tree.insert(4);

    std::cout<<"minimal number in tree: "<<tree.minimal()<<std::endl;
    
    std::cout<<"average number in tree: "<<tree.average()<<std::endl;
     std::cout<<"count of zeroes: "<<tree.countOfZeroes()<<std::endl;
       std::vector<int> levels = tree.levelsOfZeroes();
    std::cout << "Levels with zero: ";
    for (int level : levels) {
        std::cout << level << " ";
    }
    std::cout << std::endl;

       std::vector<int> levels1 = tree.levelsOfMin();
    std::cout << "Levels of mins: ";
    for (int level : levels1) {
        std::cout << level << " ";
    }
    std::cout << std::endl;

    return 0;

}