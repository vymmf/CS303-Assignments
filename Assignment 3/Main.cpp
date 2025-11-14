#include "Main.h"

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Adds a new node to be the new tail of the Queue, setting it to be at the back
template <typename T> void Queue<T>::push(const T data){
    if (empty()) {
        head = tail = new Node<T>(data);
    } else {
        // Sets the 'next' of the current tail to be the new node, then sets the previous of the new node to be the curren tail
        tail->next = new Node<T>(data);
        tail->next->previous = tail;

        // Sets the new tail to be 'next' of the previous tail, aka the new node
        tail = tail->next;
        tail->next = head;
        head->previous = tail;
    }

    numItems++;
}

    // Sets the new head to be the node before the current head, then removes the current head node
//template <typename T> void Queue<T>::pop(){
//    // Checks if Queue is empty
//    if (empty()) {
//        return;
//    }
//
//    Node<T>* temp = head;
//
//    // New head is set to be the current head's next node, then temp (current head node) is deleted
//    head = head->next;
//    delete temp;
//    numItems--;
//}

    // Variant of the normal pop function that returns the data of the node that was popped
template <typename T> T Queue<T>::pop(){
    // Checks if Queue is empty
    if (empty()) {
        return 0;
    }

    Node<T>* temp = head;

    // Save data to return later
    T returnData = temp->data;

    // New head is set to be the current head's next node, then temp (current head node) is deleted
    head = head->next;
    head->previous = tail;
    delete temp;
    numItems--;

    return returnData;
}

// Returns the current head node; functions the same as getHead()
template <typename T> Node<T>* Queue<T>::front(){
    return head;
}

// Returns the current tail node; functions the same as getTail()
template <typename T> Node<T>* Queue<T>::back(){
    return tail;
}

// Returns the number of items in the Queue
template <typename T> int Queue<T>::size(){
    return getNumItems();
}

// Returns true or false based on if the head is a nullptr
template <typename T> bool Queue<T>::empty(){
    return head == nullptr;
}

// Displays all the nodes of a Queue in order; uses size(), front(), push(), and pop() to accomplish this
template <typename T> void Queue<T>::display() {

    cout << endl; // For design purposes

    for (int i = 0; i < size(); i++) {
        cout << head->data << endl;
        push(pop());
    }

    cout << endl; // For design purposes
}

template <typename T> void Queue<T>::displaySize() {
    cout << "Size: " << size() << endl;
}

// Moves the node in the front to the back; front() isn't needed since pop always removes the front element
template <typename T> void Queue<T>::moveToRear() {
    push(pop());
}

// Altered linear search function that works with SLL Queues; returns the position of the last occurrence of an element
template <typename T> int reverseLinearSearch(Queue<T>& queue, T target, Node<T>* currentNode, int index) {

    if (currentNode == queue.front())
        return -1;

    if (target == queue.front()->data)
        return index;

    else
        return reverseLinearSearch(queue, target, currentNode->previous, index - 1);
}

int main() {
    // Queue Testing
    Queue<int> Queue{};

    cout << "--- Queue Sandbox ---" << endl;

    // Creating Queue from an array of integers
    const int arraySize = 10;
    int array[arraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Inserts each letter of the array at the head (index 0) of the Queue
    for (const auto & arrayElement : array) {
        Queue.push(arrayElement);
    }

    // Base Case, should display the queue in a state with no alterations
    Queue.display();
    Queue.displaySize();

    // 1st Test Case, should show the moveToRear() function working as intended
    Queue.moveToRear();
    Queue.display();
    Queue.displaySize();

    reverseLinearSearch<int>(Queue, 5, Queue.back(), Queue.size());

    return 0;
}