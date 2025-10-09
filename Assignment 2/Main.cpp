#include "Main.h"

#include <iostream>

using namespace std;

// Node template used for SLL
struct Node {
    // Variables that contain data & pointer to the next node of the SLL
    string data;
    Node* next;

    // Constructor
    explicit Node(const string& data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

// Adds a new node to be the new head of the SLL, setting it to be at the front
void SingleLinkedList::pushFront(const string& data = ""){
    // Sets the 'next' of the new node to be the previous head, then sets the new head to be the new node
    head = new Node(data, head);
    numItems++;
 }

// Adds a new node to be the new tail of the SLL, setting it to be at the back
void SingleLinkedList::pushBack(const string& data = ""){
    // Sets the 'next' of the current tail to be the new node
    tail->next = new Node(data);
    // Sets the new tail to be 'next' of the previous tail, aka the new node
    tail = tail->next;
    numItems++;
}

// Sets the new head to be the node before the current head, then removes the current head node
void SingleLinkedList::popFront(){
    // Checks if SLL is empty
    if (empty()) {
        return;
    }

    Node* temp = head;

    // New head is set to be the current head's next node, then temp (current head node) is deleted
    head = head->next;
    delete temp;
    numItems--;
}

// Sets the new tail to be the node after the current tail, then removes the current tail node
void SingleLinkedList::popBack(){
    // Checks if SLL is empty
    if (empty()) {
        return;
    }

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
void SingleLinkedList::insert(int index, const string& data = ""){
    // Checks if insertion is at the head
    if (index == 0) {
        head = new Node(data, head);

        // Also checks if the tail is unassigned, then assigns the head to the tail (Case for if SLL was originally empty)
        if (tail == nullptr) {
            tail = head;
        }
        return;
    }

    // Checks if SLL is empty
    if (empty()) {
        return;
    }

    Node* current = head;

    // Go to index before node at position index to be able to insert at position index
    for (int i = 0; i < index - 1; i++) {
        if (current == nullptr) {
            return;
        }

        if (current->next == nullptr && i < index - 2) {
            return;
        }

        current = current->next;
    }

    // Inserts a new node at position index
    Node* newNode = new Node(data, current->next);
    current->next = newNode;

    if (newNode->next == nullptr) {
        tail = newNode;
    }
}

// Removes a node at position index, then returns true or false based on if the operation succeeded
bool SingleLinkedList::remove(int index){
    // Checks if removal is at the head
    if (index == 0) {
        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        return true;
    }

    // Checks if SLL is empty
    if (empty()) {
        return false;
    }

    Node* current = head;

    // Go to index before node at position index to be able to remove at position index
    for (int i = 0; i < index - 1; i++) {
        if (current == nullptr) {
            return false;
        }

        if (current->next == nullptr && i < index - 2) {
            return false;
        }

        current = current->next;
    }

    // Removes a new node at position index
    current->next = current->next->next;
    delete current->next;
    return true;
}

// Returns the position of the first appearance of an item; returns the size of the SLL if not found
size_t SingleLinkedList::find(string data){

}

int main() {
    SingleLinkedList SLL{};

    Node* A = new Node("A");
    Node* B = new Node("B", A);
    Node* C = new Node("C", B);

    SLL.setHead(C);
    SLL.setTail(A);
    SLL.setNumItems(3);

    return 0;
}