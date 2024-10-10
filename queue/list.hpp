#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <typename T>
class List {
public:
    List();
    ~List();

    void push_back(T data);
    void push_front(T data);
    void pop_front();
    void print() const;
    void reverse();
    T& top() const;
    T find_n_fromEnd(int n) const;
    void insert(T data, int position);
    bool empty() const; 

protected:
    template<typename U>
    class Node {
    public:
        U data;
        Node<U>* pNext;
        Node(U newData) : data(newData), pNext(nullptr) {}
    };

    Node<T>* head;
};

#endif // LIST_HPP

template<typename T>
List<T>::List() : head(nullptr) {}

template<typename T>
List<T>::~List() {
    while (head != nullptr) {
        pop_front();
    }
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    } else {
        Node<T>* current = head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
}

template<typename T>
void List<T>::push_front(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->pNext = head;
    head = newNode;
}

template<typename T>
void List<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    Node<T>* temp = head;
    head = head->pNext;
    delete temp;
}

template<typename T>
void List<T>::insert(T data, int position) {
    if (position == 0) {
        push_front(data);
        return;
    }

    Node<T>* current = head;
    size_t currentIndex = 0;

    while (current != nullptr && currentIndex < position - 1) {
        current = current->pNext;
        currentIndex++;
    }

    if (current == nullptr) {
        return;
    }

    Node<T>* newNode = new Node<T>(data);
    newNode->pNext = current->pNext;
    current->pNext = newNode;
}

template<typename T>
void List<T>::print() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->pNext;
    }
    std::cout << std::endl;
}

template <typename T>
void List<T>::reverse() {
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->pNext;  
        current->pNext = prev;  
        prev = current;        
        current = next;        
    }
    head = prev;  
}

template<typename T>
T List<T>::find_n_fromEnd(int n) const {
    if (head == nullptr || n <= 0) {
        throw std::out_of_range("Invalid index");
    }
    int length = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        ++length;
        current = current->pNext;
    }

    int targetIndex = length - n;
    if (targetIndex < 0) {
        throw std::out_of_range("Index out of range");
    }

    current = head;
    for (int i = 0; i < targetIndex; ++i) {
        current = current->pNext;
    }

    return current->data;
}

template<typename T>
T& List<T>::top() const {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

template<typename T>
bool List<T>::empty() const {
    return head == nullptr;
}

