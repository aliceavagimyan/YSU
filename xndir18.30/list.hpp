#ifndef DOUBLY_LIST
#define DOUBLY_LIST

#include <iostream>

template <typename T>
class DoublyList {
public:
    DoublyList();
    ~DoublyList();
    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
    void insert(T data, int position);
    void remove_all(T data); 
    void print() const;
  
private:
    template <typename U>
    class Node {
    public:
        U data;
        Node<U>* pNext;
        Node<U>* pPrev;
        Node(U newData) : data(newData), pNext(nullptr), pPrev(nullptr) {}
    };

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
        head->pNext = head; 
        head->pPrev = head;  
    } else {
        newNode->pNext = head;
        newNode->pPrev = tail;
        head->pPrev = newNode;
        tail->pNext = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyList<T>::push_back(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (tail == nullptr) {
        head = tail = newNode;
        head->pNext = head;
        head->pPrev = head;
    } else {
        newNode->pPrev = tail;
        newNode->pNext = head;
        tail->pNext = newNode;
        head->pPrev = newNode;
        tail = newNode;
    }
}

template <typename T>
void DoublyList<T>::pop_front() {
    if (head == nullptr) {
        return;
    }
    Node<T>* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->pNext;
        tail->pNext = head;
        head->pPrev = tail;
    }
    delete temp;
}

template <typename T>
void DoublyList<T>::pop_back() {
    if (tail == nullptr) {
        return;
    }
    Node<T>* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->pPrev;
        tail->pNext = head;
        head->pPrev = tail;
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
    for (int i = 0; i < position - 1 && current != tail; ++i) {
        current = current->pNext;
    }

    if (current == tail) {
        push_back(data);
        return;
    }

    Node<T>* newNode = new Node<T>(data);
    newNode->pNext = current->pNext;
    newNode->pPrev = current;
    current->pNext->pPrev = newNode;
    current->pNext = newNode;
}

template <typename T>
void DoublyList<T>::remove_all(T data) {
    if (head == nullptr) {
        return;
    }

    Node<T>* current = head;
    do {
        if (current->data == data) {
            Node<T>* toDelete = current;
            if (current == head) {
                pop_front();
                current = head;
            } else if (current == tail) {
                pop_back();
                current = head;
            } else {
                current->pPrev->pNext = current->pNext;
                current->pNext->pPrev = current->pPrev;
                current = current->pNext;
                delete toDelete;
            }
        } else {
            current = current->pNext;
        }
    } while (current != head);  
}

template <typename T>
void DoublyList<T>::print() const {
    if (head == nullptr) {
        return;
    }

    Node<T>* current = head;
    do {
        std::cout << current->data << " ";
        current = current->pNext;
    } while (current != head);
    std::cout << std::endl;
}

#endif // DOUBLY_LIST
