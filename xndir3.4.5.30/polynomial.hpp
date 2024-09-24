#include <iostream>
#include <cmath>
struct Node {
    int gorcakic;
    int astichan;
    Node* next;

    Node(int coeff, int pow) : gorcakic(coeff), astichan(pow), next(nullptr) {}
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}

   
    void addTerm(int gorcakic, int astichan) {
        Node* newNode = new Node(gorcakic, astichan);
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
    double arjeqTvyalKetum(double x) {
        double result = 0.0;
        Node* temp = head;

        while (temp != nullptr) {
            result += temp->gorcakic * std::pow(x, temp->astichan);
            temp = temp->next;
        }

        return result;
    }


    void addOrUpdateTerm(int gorcakic, int astichan) {
        Node* temp = head;
        Node* prev = nullptr;

        
        while (temp != nullptr && temp->astichan > astichan) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != nullptr && temp->astichan == astichan) {
            
            temp->gorcakic += gorcakic;
        } else {
          
            Node* newNode = new Node(gorcakic, astichan);
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
                result.addTerm(-temp2->gorcakic, temp2->astichan);
                temp2 = temp2->next;
            } else if (temp2 == nullptr) {
                result.addTerm(temp1->gorcakic, temp1->astichan);
                temp1 = temp1->next;
            } else if (temp1->astichan == temp2->astichan) {
                result.addTerm(temp1->gorcakic - temp2->gorcakic, temp1->astichan);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->astichan > temp2->astichan) {
                result.addTerm(temp1->gorcakic, temp1->astichan);
                temp1 = temp1->next;
            } else {
                result.addTerm(-temp2->gorcakic, temp2->astichan);
                temp2 = temp2->next;
            }
        }

        return result;
    }

    
    Polynomial multiply(const Polynomial& other) {
        Polynomial result;

        for (Node* temp1 = this->head; temp1 != nullptr; temp1 = temp1->next) {
            for (Node* temp2 = other.head; temp2 != nullptr; temp2 = temp2->next) {
                int newgorcakic = temp1->gorcakic * temp2->gorcakic;
                int newastichan = temp1->astichan + temp2->astichan;
                result.addOrUpdateTerm(newgorcakic, newastichan);
            }
        }

        return result;
    }

    
    void print() const {
        Node* temp = head;
        bool first = true;
        while (temp != nullptr) {
            if (!first && temp->gorcakic > 0) {
                std::cout << " + ";
            }
            std::cout << temp->gorcakic << "x^" << temp->astichan;
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
