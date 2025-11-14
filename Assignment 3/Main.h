#ifndef CS303_ASSIGNMENTS_MAIN_H
#define CS303_ASSIGNMENTS_MAIN_H

#include <iostream>

using namespace std;

// Node struct used for Queue
template <typename T = string&> struct Node {
    // Variables that contain data & pointer to the next node of the Queue & pointer to the previous node of the Queue
    T data;
    Node* next;
    Node* previous;

    // Node constructor
    explicit Node(T data, Node* next = nullptr, Node* previous = nullptr) {
        this->data = data;
        this->next = next;
        this->previous = previous;
    }
};

// Reusing this class from Assignment 2 to create a Queue
template <typename T = string&> class Queue {
    private:
        // Variables
        Node<T>* head;
        Node<T>* tail;
        int numItems;

    public:
        // Setters
        void setHead(Node<T>* newHead) { head = newHead; };
        void setTail(Node<T>* newTail) { head = newTail; };
        void setNumItems(int num) { numItems = num; };

        // Getters
        [[nodiscard]] Node<T>* getHead() const { return head; } // Functions the same as front()
        [[nodiscard]] Node<T>* getTail() const { return tail; } // Functions the same as back()
        [[nodiscard]] int getNumItems() const { return numItems; }; // Functions the same as size()

        // Basic Queue Functions
        void push(T data);
        T pop(); // Variant that returns the data of the node
        //void pop();
        Node<T>* front(); // Functions the same as getHead()
        Node<T>* back(); // Functions the same as getTail()
        int size(); // Functions the same as getNumItems()
        bool empty();

        // Custom Queue Functions
        void display();
        void displaySize();
        void moveToRear();

    // Destructor for Queue Class
    ~Queue() {
        while (!empty()) {
            pop();
        }
    }
};

int main();

template <typename T> void displayQueue(const Queue<T>& Queue);

#endif //CS303_ASSIGNMENTS_MAIN_H
