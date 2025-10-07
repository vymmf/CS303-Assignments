#include "Main.h"

#include <iostream>

using namespace std;

// Node template used for SLL
struct Node {
    // Variables that contain data & pointer to the next node of the SLL
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Adds a new node to be the new head of the SLL, setting it to be at the front
void SingleLinkedList::pushFront(){
    
 }

// Adds a new node to be the new tail of the SLL, setting it to be at the back
void SingleLinkedList::pushBack(){

}

// Sets the new head to be the node before the current head, then removes the current head node
void SingleLinkedList::popFront(){

}

// Sets the new tail to be the node after the current tail, then removes the current tail node
void SingleLinkedList::popBack(){

}

// Returns the data of the current head node
void SingleLinkedList::front(){

}

// Returns the data of the current tail node
void SingleLinkedList::back(){

}

// Returns true or false based on if the head is a nullptr
bool SingleLinkedList::empty(){
    return head == nullptr;
}

// Adds a new node at position index
void SingleLinkedList::insert(){

}

// Removes a node at position index, then returns true or false based on if the operation succeeded
bool SingleLinkedList::remove(){

}

// Returns the position of the first appearance of an item; returns the size of the SLL if not found
size_t SingleLinkedList::find(){

}

int main() {
    SingleLinkedList SLL;


    return 0;
}