#ifndef LIST
#define LIST
#include <iostream>

template <typename T>
class List
{
public:
    List();
    ~List();
    void push_back(T data);
    void push_front(T data);
    void pop_front();
    void print();
    void removeDuplicates();
    void insert(T data, int position);
 
    void deleteAt(int position);
    T &operator[](int index);

    // Node<T> *getHead() const
    // {
    //     return head;
    // }

private:
    template <typename U>
    class Node
    {
    public:
        U data;
        Node<U> *pNext;
        Node(U newData) : data(newData), pNext(nullptr) {}
    };

private:
    Node<T> *head;
};

#endif // LIST

template <typename T>
List<T>::List()
{
    head = nullptr;
}

template <typename T>
List<T>::~List()
{
    while (head != nullptr)
    {
        pop_front();
    }
}

template <typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
}

template <typename T>
void List<T>::push_front(T data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->pNext = head;
    head = newNode;
}

template <typename T>
void List<T>::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
}

template <typename T>
void List<T>::insert(T data, int position)
{
    if (position == 0)
    {
        push_front(data);
        return;
    }

    Node<T> *current = head;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < position - 1)
    {
        current = current->pNext;
        currentIndex++;
    }

    if (current == nullptr)
    {
        return;
    }

    Node<T> *newNode = new Node<T>(data);
    newNode->pNext = current->pNext;
    current->pNext = newNode;
}


template <typename T>
void List<T>::deleteAt(int position)
{
    if (position == 0)
    {
        pop_front();
        return;
    }

    Node<T> *current = head;
    int  currentIndex = 0;

    while (current != nullptr && currentIndex < position - 1)
    {
        current = current->pNext;
        currentIndex++;
    }

    if (current == nullptr || current->pNext == nullptr)
    {
        return;
    }

    Node<T> *temp = current->pNext;
    current->pNext = current->pNext->pNext;
    delete temp;
}

template <typename T>
T &List<T>::operator[](int index)
{
    if (index < 0)
    {
        throw std::out_of_range("Index out of range");
    }

    Node<T> *current = head;
    for (int i = 0; i < index; ++i)
    {
        if (current == nullptr)
        {
            throw std::out_of_range("Index out of range");
        }
        current = current->pNext;
    }

    if (current == nullptr)
    {
        throw std::out_of_range("Index out of range");
    }

    return current->data;
}
template <typename T>
void List<T>::print()
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << std::endl;
        current = current->pNext;
    }
    std::cout << std::endl;
}
template <typename T>
void List<T>::removeDuplicates() {
    Node<T>* currentNode = head; 

    while (currentNode != nullptr && currentNode->pNext != nullptr) {
        Node<T>* comparisonNode = currentNode; 
        while (comparisonNode->pNext != nullptr) {
            if (comparisonNode->pNext->data == currentNode->data) {
               
                Node<T>* duplicateNode = comparisonNode->pNext;
                comparisonNode->pNext = comparisonNode->pNext->pNext;
                delete duplicateNode;
            } else {
              
                comparisonNode = comparisonNode->pNext;
            }
        }
        currentNode = currentNode->pNext; 
    }
}

