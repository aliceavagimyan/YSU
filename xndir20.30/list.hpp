#ifndef DOUBLY_LIST
#define DOUBLY_LIST

#include <iostream>

template <typename T>
class DoublyList {
   public:
    template <typename U>
    class Node {
    public:
        U data;
        Node<U>* pNext;
        Node<U>* pPrev;
        Node(U newData) : data(newData), pNext(nullptr), pPrev(nullptr) {}
    };

public:
    DoublyList();
    ~DoublyList();
    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
    void insert(T data, int position);
    void insert_after(Node<T>* node, T data);  
    void delete_node(Node<T>* node);  
    void print() const;


    Node<T>* head;
    Node<T>* tail;

    void clear();  
};

template <typename T>
DoublyList<T>::DoublyList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
}

template <typename T>
void DoublyList<T>::clear() {
    while (head != nullptr) {
        pop_front();
    }
}

template <typename T>
void DoublyList<T>::push_front(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->pNext = head;
        head->pPrev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyList<T>::push_back(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->pPrev = tail;
        tail->pNext = newNode;
        tail = newNode;
    }
}

template <typename T>
void DoublyList<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    Node<T>* temp = head;
    head = head->pNext;
    if (head != nullptr) {
        head->pPrev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

template <typename T>
void DoublyList<T>::pop_back() {
    if (tail == nullptr) {
        return;
    }
    Node<T>* temp = tail;
    tail = tail->pPrev;
    if (tail != nullptr) {
        tail->pNext = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

template <typename T>
void DoublyList<T>::insert(T data, int position) {
    if (position <= 0) {
        push_front(data);
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; ++i) {
        current = current->pNext;
    }

    if (current == nullptr || current == tail) {
        push_back(data);
        return;
    }

    Node<T>* newNode = new Node<T>(data);
    newNode->pNext = current->pNext;
    newNode->pPrev = current;

    if (current->pNext != nullptr) {
        current->pNext->pPrev = newNode;
    }
    current->pNext = newNode;
}

template <typename T>
void DoublyList<T>::insert_after(Node<T>* node, T data) {
    if (node == nullptr) {
        return;
    }

    Node<T>* newNode = new Node<T>(data);
    newNode->pNext = node->pNext;
    newNode->pPrev = node;

    if (node->pNext != nullptr) {
        node->pNext->pPrev = newNode;
    }
    node->pNext = newNode;

    if (node == tail) {  
        tail = newNode;
    }
}


template <typename T>
void DoublyList<T>::delete_node(Node<T>* node) {
    if (node == nullptr || node == head) {
        return;  
    }

    if (node == tail) {  
        tail = node->pPrev;
    }

    if (node->pPrev != nullptr) {
        node->pPrev->pNext = node->pNext;
    }
    if (node->pNext != nullptr) {
        node->pNext->pPrev = node->pPrev;
    }
    delete node;
}

template <typename T>
void DoublyList<T>::print() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->pNext;
    }
    std::cout << std::endl;
}

#endif // DOUBLY_LIST
