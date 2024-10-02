#ifndef LIST
#define LIST

#include <iostream>

struct Node {
    int data;
    Node* next;
};


class CyclicList {
private:
    Node* last;  
public:
   
    CyclicList() : last(nullptr) {}

 
    ~CyclicList() {
        if (last) {
            Node* temp = last->next;
            do {
                Node* next = temp->next;
                delete temp;
                temp = next;
            } while (temp != last->next);
            delete last;
        }
    }

   
    void append(int data) {
        Node* newNode = new Node{data, nullptr};
        if (!last) {
        
            last = newNode;
            last->next = last;  
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode; 
        }
    }

  
    void reverse() {
        if (!last || !last->next) {
            return; 
        }

        Node* prev = last;
        Node* current = last->next;  
        Node* nextNode = nullptr;
         Node* first = last->next; 

        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != last);
        last=current->next;
    
          current->next=prev;
    }

    
    void print() const {
        if (!last) return;

        Node* first = last->next; 
        Node* temp = first;

        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != first); 

        std::cout << std::endl;
    }
};

#endif //LIST