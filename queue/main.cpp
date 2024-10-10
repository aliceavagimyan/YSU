#include <iostream>
#include "queueWithList.hpp"
int main() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    q.print(); // Выведет 10, 20, 30

    q.dequeue();
    q.print(); // Выведет 20, 30

    std::cout << "Front: " << q.front() << std::endl; // Выведет 20

    return 0;
}
