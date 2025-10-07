#ifndef CS303_ASSIGNMENTS_MAIN_H
#define CS303_ASSIGNMENTS_MAIN_H

#include <iostream>

using namespace std;

struct Node;

class SingleLinkedList {
    private:
        Node* head;
        Node* tail;
        int numItems;
    public:
        void setHead(Node* head);
        void setTail(Node* tail);
        void setNumItems(int num);

        Node* getHead() const { return head; }
        Node* getTail() const { return tail; }
        int getNumItems() const { return numItems; };

        void pushFront(string data);
        void pushBack(string data);
        void popFront();
        void popBack();
        string front();
        string back();
        bool empty();
        void insert();
        bool remove();
        size_t find();
};

class Main {
    int main();
};


#endif //CS303_ASSIGNMENTS_MAIN_H
