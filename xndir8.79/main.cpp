#include <iostream>
#include <queue>

std::queue<int> removeDuplicates(std::queue<int>& S1) {
    std::queue<int> S2;
    std::queue<int> temp; 

    while (!S1.empty()) {
        int value = S1.front();
        S1.pop(); 

       
        bool found = false;
        std::queue<int> tempQueue = S2; 

        while (!tempQueue.empty()) {
            if (tempQueue.front() == value) {
                found = true; 
                break;
            }
            tempQueue.pop();
        }

       
        if (!found) {
            S2.push(value);
        }
        temp.push(value);
    }
    while (!temp.empty()) {
        S1.push(temp.front());
        temp.pop();
    }

    return S2;
}

int main() {
    std::queue<int> S1;

    
    S1.push(1);
    S1.push(2);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(4);
    S1.push(5);

    std::queue<int> S2 = removeDuplicates(S1);

  
    while (!S2.empty()) {
        std::cout << S2.front() << " ";
        S2.pop();
    }

    return 0;
}
