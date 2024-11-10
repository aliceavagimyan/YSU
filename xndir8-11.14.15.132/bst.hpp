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
    int countNodes() const;
    int countLeaves() const;
    int height() const;
    int countX(const T& val) const;
    void countLevelByLevel() ;
  void levelByLevel();
   
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    void printInOrder(Node* node) const;
    void clear(Node* node);
    int countNodes(Node* node) const;
    int countLeaves(Node* node) const;
    int height(Node* node) const;
    int countX(Node* node,const T& val) const;
    void levelByLevel(Node* root)  ;
  
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
int BST<T>::countNodes() const {
    return countNodes(root);
}

template <typename T>
int BST<T>::countNodes(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}
template <typename T>
int BST<T>::countLeaves() const{
    countLeaves(root);
    
}
template <typename T>
int BST<T>::countLeaves(Node* node) const{
    if(node==nullptr){
        return 0;
    }
    if(node->left==nullptr && node->right==nullptr){
        return 1;
    }

  return countLeaves(node->left) + countLeaves(node->right);

}
template <typename T>
int BST<T>::height() const{
   height(root);
    
}
template <typename T>
int BST<T>::height(Node* node) const{
    if(node==nullptr){
        return -1;
    }
    int leftH=height(node->left);
     int rightH=height(node->right);

  return 1 + std::max(leftH,rightH);

}
template <typename T>
int BST<T>::countX(const T& val) const{
   countX(root,val);
    
}
template <typename T>
int BST<T>::countX(Node* node,const T& val) const{
    if(node==nullptr){
        return 0;
    }
    int count=(node->data==val) ? 1:0;

  return count+(countX(node->left,val))+(countX(node->right,val));

}
template <typename T>
void BST<T>::countLevelByLevel() {
    if (!root) return;

    std::queue<Node*> queue;
    queue.push(root);

    int level = 0;
    while (!queue.empty()) {
        int levelSize = queue.size(); 
        std::cout << "Level " << level << " size: " << levelSize << std::endl;
        level++;

     
        for (int i = 0; i < levelSize; ++i) {  
            Node* node = queue.front();
            queue.pop();

            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
        }
    }
}
template <typename T>
void BST<T>::levelByLevel() {
    levelByLevel(root);
}
template <typename T>
void BST<T>::levelByLevel(Node* root) {
    if (root == nullptr) return;

    std::queue<Node*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        Node* current = nodes.front();
        nodes.pop();
        std::cout << current->value << " ";

        if (current->left != nullptr) nodes.push(current->left);
        if (current->right != nullptr) nodes.push(current->right);
    }
}


#endif // BST_HPP
