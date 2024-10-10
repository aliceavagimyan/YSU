#include <iostream>
#include <stack>

std::stack<int> mergeStacks(std::stack<int>& S1, std::stack<int>& S2) {
    std::stack<int> S3;

    while (!S1.empty() || !S2.empty()) {
        if (!S1.empty()) {
            S3.push(S1.top());
            S1.pop();
        }
        if (!S2.empty()) {
            S3.push(S2.top());
            S2.pop();
        }
    }

    return S3; 
}

void printStackReversed(std::stack<int> s) {
    std::stack<int> temp;
    
    
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

   
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> S1, S2;

    
    S1.push(3);
    S1.push(2);
    S1.push(1);

  
    S2.push(8);
    S2.push(7);
    S2.push(6);
    S2.push(5);
    S2.push(4);

    
    std::stack<int> S3 = mergeStacks(S1, S2);

    
    std::cout << "S3 : ";
    printStackReversed(S3);

    return 0;
}
