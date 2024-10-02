#ifndef DOUBLY_LIST
#define DOUBLY_LIST

#include <iostream>
#include <algorithm> 

template <typename T>
class DoublyList {

private:
    template <typename U>
    class Node {
    public:
        U data;
        Node<U>* pNext;
        Node<U>* pPrev;
        Node(U newData) : data(newData), pNext(nullptr), pPrev(nullptr) {}
    };

public:
    class Iterator;

    Node<T>* head;
    Node<T>* tail;

public:
    DoublyList();
    ~DoublyList();
    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
    void insert(T data, int position);
    void remove_all(T data);
    void bubble_sort();
    void print() const;

    Iterator begin() { return Iterator(head, this); }
    Iterator end() { return Iterator(nullptr, this); }

    void clear();

   
    class Iterator {
    private:
        Node<T>* current;
        const DoublyList<T>* list;

    public:
        Iterator(Node<T>* node, const DoublyList<T>* lst) : current(node), list(lst) {}

        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            if (current) {
                current = current->pNext;
                if (current == list->head) {
                    current = nullptr; 
                }
            }
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
        bool is_end() const {
        return current == nullptr;
    }

    bool is_begin() const {
        return current == list->head;
    }
    };
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
        tail->pNext = newNode;
        head->pPrev = newNode; 
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
    if (head == nullptr) return; 
    Node<T>* temp = head;
    if (head == tail) { 
        head = tail = nullptr;
    } else {
        head = head->pNext;
        head->pPrev = tail; 
        tail->pNext = head; 
    }
    delete temp;
}

template <typename T>
void DoublyList<T>::pop_back() {
    if (tail == nullptr) return; 
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
void DoublyList<T>::bubble_sort() {
    if (head == nullptr || head->pNext == head) { 
        return; 
    }

    bool swapped;
    do {
        swapped = false;
        Node<T>* current = head;
        do {
            Node<T>* next = current->pNext;
            if (current->data > next->data) {
                std::swap(current->data, next->data);
                swapped = true;
            }
            current = next;
        } while (current != head);
    } while (swapped);
}

template <typename T>
void DoublyList<T>::print() const {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
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
