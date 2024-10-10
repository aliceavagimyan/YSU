#include <iostream>
#include <stack>

std::stack<int> getUniqueElements(std::stack<int> &S1)
{
    std::stack<int> S2;
    std::stack<int> temp;
    while (!S1.empty())
    {
        temp.push(S1.top());
        S1.pop();
    }

    while (!temp.empty())
    {
        int current = temp.top();
        temp.pop();

        std::stack<int> checkStack = S2;
        bool isUnique = true;

        while (!checkStack.empty())
        {
            if (checkStack.top() == current)
            {
                isUnique = false;
                break;
            }
            checkStack.pop();
        }

        if (isUnique)
        {
            S2.push(current);
        }
    }

    return S2;
}

void printStack(std::stack<int> s)
{
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::stack<int> S1;

    S1.push(5);
    S1.push(3);
    S1.push(2);
    S1.push(1);
    S1.push(2);
    S1.push(4);
    S1.push(3);

    std::stack<int> S2 = getUniqueElements(S1);

    std::cout << " S2 : ";
    printStack(S2);

    return 0;
}
