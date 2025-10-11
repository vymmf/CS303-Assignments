#ifndef CS303_ASSIGNMENTS_MAIN_H
#define CS303_ASSIGNMENTS_MAIN_H

#include <iostream>

using namespace std;

// Node struct used for SLL
struct Node {
    // Variables that contain data & pointer to the next node of the SLL
    string data;
    Node* next;

    // Node constructor
    explicit Node(const string& data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class SingleLinkedList {
    private:
        Node* head;
        Node* tail;
        int numItems;
    public:
        void setHead(Node* newHead) { head = newHead; };
        void setTail(Node* newTail) { head = newTail; };
        void setNumItems(int num) { numItems = num; };

        [[nodiscard]] Node* getHead() const { return head; }
        [[nodiscard]] Node* getTail() const { return tail; }
        [[nodiscard]] int getNumItems() const { return numItems; };

        void pushFront(const string& data);
        void pushBack(const string& data);
        void popFront();
        void popBack();
        string front();
        string back();
        bool empty();
        void insert(int index, const string& data);
        bool remove(int index);
        size_t find(const string& data);

    ~SingleLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

class Stack {
private:
    vector<int> elements;

public:
    bool isEmpty() const;
    void push(int value);
    void pop();
    int top();
    size_t size();
    double average();
    void display();
};

int main();

void displaySLL(const SingleLinkedList& SLL);
void displayHead(const SingleLinkedList& SLL);
void displayTail(const SingleLinkedList& SLL);
void displayHeadAndTail(const SingleLinkedList& SLL);

void displayStack(const Stack& STK);

#endif //CS303_ASSIGNMENTS_MAIN_H
