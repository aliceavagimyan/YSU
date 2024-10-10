#include <iostream>
#include <queue>

void insertSorted(std::queue<int>& q, int value) {
  
    std::queue<int> tempQueue;
    while (!q.empty() && q.front() <= value) {
        tempQueue.push(q.front());
        q.pop();
    }

   
    tempQueue.push(value);

    
    while (!q.empty()) {
        tempQueue.push(q.front());
        q.pop();
    }

    
    q = tempQueue;
}

std::queue<int> sortQueue(std::queue<int>& inputQueue) {
    std::queue<int> sortedQueue;
 while (!inputQueue.empty()) {
        int value = inputQueue.front();
        inputQueue.pop();
        insertSorted(sortedQueue, value);
    }

    return sortedQueue;
}

int main() {
    std::queue<int> C1;

  
    C1.push(3);
    C1.push(1);
    C1.push(4);
    C1.push(1);
    C1.push(5);
    C1.push(9);

   
    std::queue<int> C2 = sortQueue(C1);

   
    while (!C2.empty()) {
        std::cout << C2.front() << " ";
        C2.pop();
    }

    return 0;
}
