#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <queue>

template <typename T>
class BST {
public:
    BST();
    ~BST();
    void insert(const T& value);
    bool find(const T& value) const;
    void remove(const T& value);
    void printInOrder() const;
    void updateSubtreeSizes();//42
    void printSubtreeSizes() const; 
    void updateLeafCounts();   //43      
    void printLeafCounts() const;    
 void updateHeights();          //45
    void printHeights() const;     
      void updateInternalCounts();    //44
    void printInternalCounts() const;
      void updateMinPresence();     //46
    void printMinPresence() const;

private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int subtreeSize;
        int leafCount;
        int height;
        int internalNodesCount;
        int minPresence;
        Node(const T& value) : data(value), left(nullptr), right(nullptr), subtreeSize(1) {}
    };

    Node* root;

    void printInOrder(Node* node) const;
    void clear(Node* node);
    int updateSubtreeSizes(Node* node);//42
    void printSubtreeSizes(Node* node) const;
    int updateLeafCounts(Node* node);//43
    void printLeafCounts(Node* node) const;
    int updateHeights(Node* node);//45
    void printHeights(Node* node) const;
     int updateInternalCounts(Node* node);//44
    void printInternalCounts(Node* node) const;
        T findMin(Node* node) const;//46
    bool checkMinPresence(Node* node, const T& minValue);
    void printMinPresence(Node* node) const;

   
};

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    clear(root);
}

template <typename T>
void BST<T>::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
void BST<T>::insert(const T& value) {
    Node** current = &root;
    while (*current) {
        if (value < (*current)->data) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    *current = new Node(value);
}

template <typename T>
bool BST<T>::find(const T& value) const {
    Node* current = root;
    while (current) {
        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

template <typename T>
void BST<T>::remove(const T& value) {
    Node** current = &root;
    Node* parent = nullptr;
    
    while (*current && (*current)->data != value) {
        parent = *current;
        if (value < (*current)->data) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    
    if (*current) {
        Node* nodeToDelete = *current;
        
        if (!(*current)->left) {
            *current = (*current)->right;
        } else if (!(*current)->right) {
            *current = (*current)->left;
        } else {
            Node** successor = &((*current)->right);
            while ((*successor)->left) {
                successor = &((*successor)->left);
            }
            (*current)->data = (*successor)->data;
            nodeToDelete = *successor;
            *successor = (*successor)->right;
        }
        delete nodeToDelete;
    }
}

template <typename T>
void BST<T>::printInOrder() const {
    printInOrder(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::printInOrder(Node* node) const {
    if (node) {
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }
}

template <typename T>
void BST<T>::updateSubtreeSizes() {
    updateSubtreeSizes(root);
}

template <typename T>
int BST<T>::updateSubtreeSizes(Node* node) {
    if (!node) return 0;
    node->subtreeSize = 1 + updateSubtreeSizes(node->left) + updateSubtreeSizes(node->right);
    return node->subtreeSize;
}

template <typename T>
void BST<T>::printSubtreeSizes() const {
    printSubtreeSizes(root);
}

template <typename T>
void BST<T>::printSubtreeSizes(Node* node) const {
    if (node) {
        printSubtreeSizes(node->left);
        std::cout << "Node " << node->data << ": Subtree size = " << node->subtreeSize << std::endl;
        printSubtreeSizes(node->right);
    }
}


template <typename T>
void BST<T>::updateLeafCounts() {
    updateLeafCounts(root);
}

template <typename T>
int BST<T>::updateLeafCounts(Node* node) {
    if (!node) return 0;

    if (!node->left && !node->right) {
        node->leafCount = 1; 
    } else {
        node->leafCount = updateLeafCounts(node->left) + updateLeafCounts(node->right);
    }
    return node->leafCount;
}

template <typename T>
void BST<T>::printLeafCounts() const {
    printLeafCounts(root);
}

template <typename T>
void BST<T>::printLeafCounts(Node* node) const {
    if (node) {
        printLeafCounts(node->left);
        std::cout << "Node " << node->data << ": Leaf count = " << node->leafCount << std::endl;
        printLeafCounts(node->right);
    }
}
template <typename T>
void BST<T>::updateHeights() {
    updateHeights(root);
}

template <typename T>
int BST<T>::updateHeights(Node* node) {
    if (!node) return -1; 
    int leftHeight = updateHeights(node->left);
    int rightHeight = updateHeights(node->right);

   
    node->height = 1 + std::max(leftHeight, rightHeight);
    return node->height;
}

template <typename T>
void BST<T>::printHeights() const {
    printHeights(root);
}

template <typename T>
void BST<T>::printHeights(Node* node) const {
    if (node) {
        printHeights(node->left);
        std::cout << "Node " << node->data << ": Height = " << node->height << std::endl;
        printHeights(node->right);
    }
}
template <typename T>
void BST<T>::updateInternalCounts() {
    updateInternalCounts(root);
}

template <typename T>
int BST<T>::updateInternalCounts(Node* node) {
    if (!node) return 0; 
    int leftInternal = updateInternalCounts(node->left);
    int rightInternal = updateInternalCounts(node->right);

   
    int isInternal = (node->left || node->right) ? 1 : 0;

  
    node->internalNodesCount = isInternal + leftInternal + rightInternal;
    return node->internalNodesCount;
}

template <typename T>
void BST<T>::printInternalCounts() const {
    printInternalCounts(root);
}

template <typename T>
void BST<T>::printInternalCounts(Node* node) const {
    if (node) {
        printInternalCounts(node->left);
        std::cout << "Node " << node->data << ": Internal Nodes Count = " << node->internalNodesCount << std::endl;
        printInternalCounts(node->right);
    }
}

template <typename T>
T BST<T>::findMin(Node* node) const {
    if (!node) throw std::runtime_error("Tree is empty");
    while (node->left) node = node->left;
    return node->data;
}

template <typename T>
void BST<T>::updateMinPresence() {
    if (!root) return; 
    T minValue = findMin(root); 
    checkMinPresence(root, minValue);
}

template <typename T>
bool BST<T>::checkMinPresence(Node* node, const T& minValue) {
    if (!node) return false;

    
    bool leftContains = checkMinPresence(node->left, minValue);
    bool rightContains = checkMinPresence(node->right, minValue);

    
    node->minPresence = (node->data == minValue || leftContains || rightContains) ? 1 : 0;

    return node->minPresence == 1;
}

template <typename T>
void BST<T>::printMinPresence() const {
    printMinPresence(root);
}

template <typename T>
void BST<T>::printMinPresence(Node* node) const {
    if (node) {
        printMinPresence(node->left);
        std::cout << "Node " << node->data << ": Min Presence = " << node->minPresence << std::endl;
        printMinPresence(node->right);
    }
}
#endif // BST_HPP
