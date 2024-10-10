#include <iostream>
#include <queue>

std::queue<int> mergeQueues(std::queue<int>& S1, std::queue<int>& S2) {
    std::queue<int> S3;

    while (!S1.empty() && !S2.empty()) {
        S3.push(S1.front());
        S1.pop();
        S3.push(S2.front());
        S2.pop();
    }

    while (!S1.empty()) {
        S3.push(S1.front());
        S1.pop();
    }

    while (!S2.empty()) {
        S3.push(S2.front());
        S2.pop();
    }

    return S3;
}

int main() {
    std::queue<int> S1;
    std::queue<int> S2;

   
    S1.push(1);
    S1.push(2);
    S1.push(3);

   
    S2.push(4);
    S2.push(5);

  
    std::queue<int> S3 = mergeQueues(S1, S2);

    while (!S3.empty()) {
        std::cout << S3.front() << " ";
        S3.pop();
    }

    return 0;
}
