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
        void setHead();
        void setTail();
        void setNumItems();

        Node* getHead() const { return head; }
        Node* getTail() const { return tail; }
        int getNumItems() const { return numItems; };

        void pushFront();
        void pushBack();
        void popFront();
        void popBack();
        void front();
        void back();
        bool empty();
        void insert();
        bool remove();
        size_t find();
};

class Main {
    int main();
};


#endif //CS303_ASSIGNMENTS_MAIN_H
