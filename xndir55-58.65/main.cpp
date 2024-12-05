#include "bst.hpp"
#include <iostream>
int main(){
BST<int> tree;
tree.insert(10);
tree.insert(5);
tree.insert(15);
tree.insert(3);
tree.insert(7);

tree.printInOrder(); 
//55

// tree.remove(5);

// tree.printInOrder(); 
//56
// tree.removeLeaves();

//     std::cout << "after removing leaves: ";
//     tree.printInOrder();
//57
// tree.makeComplete();

//     std::cout << "after making complete ";
//     tree.printInOrder();
//65
  tree.removeLevel(1);

    std::cout << "Tree after removing level 1:" << std::endl;
    tree.printInOrder();

return 0;
}
