#include <iostream>
#include <cmath>
struct Node {
    int coefficient;
    int power;
    Node* next;

    Node(int coeff, int pow) : coefficient(coeff), power(pow), next(nullptr) {}
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}

   
    void addTerm(int coefficient, int power) {
        Node* newNode = new Node(coefficient, power);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    double evaluate(double x) {
        double result = 0.0;
        Node* temp = head;

        while (temp != nullptr) {
            result += temp->coefficient * std::pow(x, temp->power);
            temp = temp->next;
        }

        return result;
    }


    void addOrUpdateTerm(int coefficient, int power) {
        Node* temp = head;
        Node* prev = nullptr;

        
        while (temp != nullptr && temp->power > power) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != nullptr && temp->power == power) {
            
            temp->coefficient += coefficient;
        } else {
          
            Node* newNode = new Node(coefficient, power);
            if (prev == nullptr) {
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = temp;
                prev->next = newNode;
            }
        }
    }
  
    Polynomial subtract(const Polynomial& other) {
        Polynomial result;
        Node* temp1 = this->head;
        Node* temp2 = other.head;

        while (temp1 != nullptr || temp2 != nullptr) {
            if (temp1 == nullptr) {
                result.addTerm(-temp2->coefficient, temp2->power);
                temp2 = temp2->next;
            } else if (temp2 == nullptr) {
                result.addTerm(temp1->coefficient, temp1->power);
                temp1 = temp1->next;
            } else if (temp1->power == temp2->power) {
                result.addTerm(temp1->coefficient - temp2->coefficient, temp1->power);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->power > temp2->power) {
                result.addTerm(temp1->coefficient, temp1->power);
                temp1 = temp1->next;
            } else {
                result.addTerm(-temp2->coefficient, temp2->power);
                temp2 = temp2->next;
            }
        }

        return result;
    }

    
    Polynomial multiply(const Polynomial& other) {
        Polynomial result;

        for (Node* temp1 = this->head; temp1 != nullptr; temp1 = temp1->next) {
            for (Node* temp2 = other.head; temp2 != nullptr; temp2 = temp2->next) {
                int newCoefficient = temp1->coefficient * temp2->coefficient;
                int newPower = temp1->power + temp2->power;
                result.addOrUpdateTerm(newCoefficient, newPower);
            }
        }

        return result;
    }

    
    void print() const {
        Node* temp = head;
        bool first = true;
        while (temp != nullptr) {
            if (!first && temp->coefficient > 0) {
                std::cout << " + ";
            }
            std::cout << temp->coefficient << "x^" << temp->power;
            temp = temp->next;
            first = false;
        }
        std::cout << std::endl;
    }

    ~Polynomial() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
