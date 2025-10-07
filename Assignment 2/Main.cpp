#include "Main.h"

#include <iostream>

using namespace std;

// Node template used for SLL
struct Node {
    // Variables that contain data & pointer to the next node of the SLL
    string data;
    Node* next;

    // Constructor
    Node(const string& data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

// Adds a new node to be the new head of the SLL, setting it to be at the front
void SingleLinkedList::pushFront(string data){
    // Sets the 'next' of the new node to be the previous head, then sets the new head to be the new node
    head = new Node(data, head);
    numItems++;
 }

// Adds a new node to be the new tail of the SLL, setting it to be at the back
void SingleLinkedList::pushBack(string data){
    // Sets the 'next' of the current tail to be the new node
    tail->next = new Node(data);
    // Sets the new tail to be 'next' of the previous tail, aka the new node
    tail = tail->next;
    numItems++;
}

// Sets the new head to be the node before the current head, then removes the current head node
void SingleLinkedList::popFront(){
    Node* temp = head;

    head = head->next;
    delete temp;
    numItems--;
}

// Sets the new tail to be the node after the current tail, then removes the current tail node
void SingleLinkedList::popBack(){
    Node* current = head;

    // Checks if the SLL has more than 1 node (Need at least 2 nodes for there to be a tail)
    if (current->next == nullptr) {
        return;
    }

    // Moves down the SLL until it reaches a node where the next node's next node is a null pointer
    while (current->next->next != nullptr) {
        current = current->next;
    }

    // Deletes the current tail then sets the current node to be the new tail
    delete current->next;
    current->next = nullptr;
    numItems--;
}

// Returns the data of the current head node
string SingleLinkedList::front(){
    return head->data;
}

// Returns the data of the current tail node
string SingleLinkedList::back(){
    return tail->data;
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

    Node* A = new Node("A");
    Node* B = new Node("B", A);
    Node* C = new Node("C", B);

    SLL.setHead(C);
    SLL.setTail(A);
    SLL.setNumItems(3);

    return 0;
}