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
    void printInOrder() const;
    void remove(const T& value);//55
    void  removeLeaves();//56
    void makeComplete() ;//57
    void clear();//58
    void removeLevel(int level);//65
    

    
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int subtreeSize;
        Node(const T& value) : data(value), left(nullptr), right(nullptr), subtreeSize(1) {}
    };

    Node* root;
       
    void printInOrder(Node* node) const;
    void clear(Node* node);
    void removeSubtree(Node*& node, const T& value);
    void removeLeaves(Node*& node);
    void collectInOrder(Node* node, std::vector<T>& elements) const;
    Node* buildCompleteTree(const std::vector<T>& elements, int start, int end);
    void removeLevel(Node*& node, int targetLevel, int currentLevel);
   
};
#endif //BST_HPP

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
        node=nullptr;
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

// template <typename T>
// void BST<T>::remove(const T& value) {
//     Node** current = &root;
//     Node* parent = nullptr;
    
//     while (*current && (*current)->data != value) {
//         parent = *current;
//         if (value < (*current)->data) {
//             current = &((*current)->left);
//         } else {
//             current = &((*current)->right);
//         }
//     }
    
//     if (*current) {
//         Node* nodeToDelete = *current;
        
//         if (!(*current)->left) {
//             *current = (*current)->right;
//         } else if (!(*current)->right) {
//             *current = (*current)->left;
//         } else {
//             Node** successor = &((*current)->right);
//             while ((*successor)->left) {
//                 successor = &((*successor)->left);
//             }
//             (*current)->data = (*successor)->data;
//             nodeToDelete = *successor;
//             *successor = (*successor)->right;
//         }
//         delete nodeToDelete;
//     }
// }
template <typename T>
void BST<T>::remove(const T& value) {
    removeSubtree(root, value);
}

template <typename T>
void BST<T>::removeSubtree(Node*& node, const T& value) {
    if (!node) {
        return; 
    }
    if (value < node->data) {
        removeSubtree(node->left, value); 
    } else if (value > node->data) {
        removeSubtree(node->right, value); 
    } else {
        clear(node); 
        node = nullptr; 
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
void BST<T>::clear() {
    clear(root);  
    root = nullptr;  
}

template <typename T>
void BST<T>::removeLeaves() {
    removeLeaves(root);
}

template <typename T>
void BST<T>::removeLeaves(Node*& node) {
    if (!node) return;

    if (!node->left && !node->right) { 
        delete node;
        node = nullptr;
        return;
    }

    removeLeaves(node->left);
    removeLeaves(node->right);
}
template <typename T>
void BST<T>::makeComplete() {
    std::vector<T> elements;
    collectInOrder(root, elements); 
    clear(root);                    
    root = buildCompleteTree(elements, 0, elements.size() - 1); 
}

template <typename T>
void BST<T>::collectInOrder(Node* node, std::vector<T>& elements) const {
    if (node) {
        collectInOrder(node->left, elements);
        elements.push_back(node->data);
        collectInOrder(node->right, elements);
    }
}

template <typename T>
typename BST<T>::Node* BST<T>::buildCompleteTree(const std::vector<T>& elements, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* newNode = new Node(elements[mid]);
    newNode->left = buildCompleteTree(elements, start, mid - 1);
    newNode->right = buildCompleteTree(elements, mid + 1, end);
    return newNode;
}
template <typename T>
void BST<T>::removeLevel(int level) {
    removeLevel(root, level, 0);
}

template <typename T>
void BST<T>::removeLevel(Node*& node, int targetLevel, int currentLevel) {
    if (!node) return;

    if (currentLevel + 1 == targetLevel) {
       
        clear(node->left);
        clear(node->right);
        node->left = nullptr;
        node->right = nullptr;
        return;
    }

   
    removeLevel(node->left, targetLevel, currentLevel + 1);
    removeLevel(node->right, targetLevel, currentLevel + 1);
}

