#include <iostream>
#include "bst.hpp"

int main() {
    BST<int> tree;

  
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // 42
    tree.updateSubtreeSizes();

    std::cout << "Subtree sizes for each node:" << std::endl;
    tree.printSubtreeSizes();
//43
     tree.updateLeafCounts();

    std::cout << "Leaf counts for each node:" << std::endl;
    tree.printLeafCounts();
    //45
     tree.updateHeights();


    std::cout << "Heights for each node:" << std::endl;
    tree.printHeights();
  //44
     tree.updateInternalCounts();

    std::cout << "Internal nodes count for each node:" << std::endl;
    tree.printInternalCounts();
   //46
    tree.updateMinPresence();

    std::cout << "Minimum element presence for each node:" << std::endl;
    tree.printMinPresence();


    return 0;
}
