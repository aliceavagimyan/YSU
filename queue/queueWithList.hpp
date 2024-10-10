#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"

template <typename T>
class Queue : private List<T> {
public:
    Queue() : List<T>(), tail(nullptr) {}

    void enqueue(T data) {
        this->push_back(data);  
        if (this->tail == nullptr) {
            this->tail = this->head;  
        } else {
            typename List<T>::template Node<T>* current = this->head;  
            while (current->pNext != nullptr) {
                current = current->pNext;
            }
            this->tail = current;  
        }
    }

    void dequeue() {
        if (!this->empty()) {
            this->pop_front();
            if (this->empty()) {
                tail = nullptr;
            }
        } else {
            throw std::runtime_error("Queue is empty, cannot dequeue");
        }
    }

    T& front() const {
        return this->top();
    }

    bool empty() const {
        return this->List<T>::empty();
    }

    void print() const {
        this->List<T>::print();
    }

private:
    typename List<T>::template Node<T>* tail;  // Указатель на последний элемент
};

#endif // QUEUE_HPP
