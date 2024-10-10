#include <iostream>
#include <stack>

void sortStack(std::stack<int>& C1, std::stack<int>& C2) {

    while (!C1.empty()) {
        
        int temp = C1.top();
        C1.pop();

        
        while (!C2.empty() && C2.top() > temp) {
            C1.push(C2.top());
            C2.pop();
        }

        C2.push(temp);
    }
}

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> C1;
    std::stack<int> C2;

    
    C1.push(3);
    C1.push(1);
    C1.push(4);
    C1.push(2);
    C1.push(5);
    printStack(C1);
   
    sortStack(C1, C2);

    
    std::cout << "C2: ";
    printStack(C2);

    return 0;
}
