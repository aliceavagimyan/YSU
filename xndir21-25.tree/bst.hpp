#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class BST {
public:
    BST();
    ~BST();
    void insert(const T& value);
    bool find(const T& value) const;
    void remove(const T& value);
    void printInOrder() const;
    int minimal() const; //xndir 21
    int average() ; //xndir 22
    int countOfZeroes() const;//xndir 23
    std::vector<int> levelsOfZeroes() const; //xndir 24
    std::vector<int> levelsOfMin() const;// xndir25
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
    void average(Node* node,int& sum, int& count);
     int countOfZeroes(Node* node) const;
    
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
int BST<T>::minimal() const{
    if(!root){
        return -1 ;
    }
    Node* current=root;
    while(current->left){
        current=current->left;
    }
    return current->data;
}
template <typename T>
int BST<T>::average() {
    if(!root){
        return -1;
    }
    int count=0;
    int sum=0;
    average(root,sum,count);
    return sum/count;
}
template <typename T>
void BST<T>::average(Node* node,int& sum,int& count){
    if(!node) return;
    average(node->left,sum,count);
    sum+=node->data;
    ++count;
    average(node->right,sum,count);
}

template <typename T>
int BST<T>::countOfZeroes() const{
    return countOfZeroes(root);
}
template <typename T>
int BST<T>::countOfZeroes(Node* node) const{
   if(!node){
    return 0;
   }
   int count=0;
   if(node->data==0){
    ++count;
   }
   return count+countOfZeroes(node->left)+countOfZeroes(node->right);
}
template <typename T>
std::vector<int> BST<T>::levelsOfZeroes() const {
    std::vector<int> result;
    if (!root) return result;

    std::queue<std::pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        Node* current = q.front().first;
        int level = q.front().second;
        q.pop();

       
        if (current->data == 0 && (result.empty() || result.back() != level)) {
            result.push_back(level);
        }

    
        if (current->left) {
            q.push({current->left, level + 1});
        }
        if (current->right) {
            q.push({current->right, level + 1});
        }
    }

    return result;
}
template <typename T>
std::vector<int> BST<T>::levelsOfMin() const {
    std::vector<int> result;
    if (!root) return result;


    T minValue = minimal();

   
    std::queue<std::pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        Node* current = q.front().first;
        int level = q.front().second;
        q.pop();

        
        if (current->data == minValue) {
            
            if (result.empty() || result.back() != level) {
                result.push_back(level);
            }
        }

        
        if (current->left) {
            q.push({current->left, level + 1});
        }
        if (current->right) {
            q.push({current->right, level + 1});
        }
    }

    return result;
}





#endif // BST_HPP
