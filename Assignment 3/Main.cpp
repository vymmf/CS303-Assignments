#include "Main.h"

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

    // Queue Methods

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

    // Variant of the normal pop function that returns the data of the node that was popped, customized for circular queues
    template <typename T> T Queue<T>::pop() {
        if (empty()) {
            throw runtime_error("Pop from empty queue");
        }

        Node<T>* temp = head;
        T returnData = temp->data;

        if (head == tail) {
            // Checks if there's only 1 element in the queue, in which the node becomes a nullptr
            head = tail = nullptr;
        } else {
            // Process for when there isn't only 1 element
            head = head->next;
            head->previous = tail;
            tail->next = head;
        }

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

// Displays the current size (number of elements, not max index) of the Queue
template <typename T> void Queue<T>::displaySize() {
    cout << "Size: " << size() << endl;
}

// Moves the node in the front to the back; front() isn't needed since pop always removes the front element
template <typename T> void Queue<T>::moveToRear() {
    push(pop());
}

    // Queue Functions

// Altered linear search function that works with SLL Queues; returns the position of the last occurrence of an element
template <typename T> int reverseLinearSearch(Queue<T>& queue, T target, Node<T>* currentNode, int index) {
    // Checks if Queue is empty
    if (queue.empty()) {
        return -1;
    }

    // Index should start at the back of the SLL Queue, starting at the value size() - 1, since Queues start at index 0 and not 1
    if (index == queue.size())
        index--;

    // Base Case 1: Checks if the current node is the tail, in which we've reached the end of the Queue without finding the target
    // Updated Base Case 1: Checks if the index is negative, then returns the index
    if (index < 0) // If this doesn't work, revert back to currentNode == queue.back() && index != queue.size() - 1
        return -1; // Theoretically, the index should always be -1 at this state; Updated, will simply just return -1 to be safe

    // Base Case 2: Checks if the current node has the data, in which the returns the index
    if (target == currentNode->data)
        return index;

    // Recursive Case/Call
    else
        return reverseLinearSearch(queue, target, currentNode->previous, index - 1);
}

// Displays the results of the reverse linear search
template <typename T> void displayRLSResults(T target, int targetIndex) {
    cout << "Reverse Linear Search: Found last instance of " << target << " at index: " << targetIndex << endl;
}

// Insertion Sort function that works with circular queues; Inserts an element in the correct position based on if it's less than a specific value within the queue
template <typename T> void insertionSort(Queue<T>& queue) {
    // Checks if Queue only has 1 or fewer elements and if it's empty, ends function early
    if (queue.size() <= 1 || queue.empty())
        return;

    // Variables/Objects
    Queue<T> sortedQueue{};
    int size = queue.size();

    // Convert Circular Queue to Linear Queue for easier sorting
    for (int i = 0; i < size; i++) {
        T current = queue.pop();

        // Temporary Queue to find insertion point
        Queue<T> temp{};
        bool inserted = false;
        int sortedSize = sortedQueue.size();

        // Adds elements from the sorted queue into the temporary queue, but also checks for when the insertion of the current element should happen
        for (int j = 0; j < sortedSize; j++) {
            T sortedElement = sortedQueue.pop();
            // Checks if the current element is less than the current element in the sorted queue, then adds it to the temp queue if so; this is where the insertion happens
            if (!inserted && current < sortedElement) {
                temp.push(current);
                inserted = true;
            }
            temp.push(sortedElement);
        }

        // Used for the first iteration of the i loop, since the sorted size will be 0, thus skipping the j loop and making inserted true
        if (!inserted) {
            temp.push(current);
        }

        // Moves all elements in the temporary queue back into the sorted queue
        while (!temp.empty()) {
            sortedQueue.push(temp.pop());
        }
    }

    // Moves all elements in the sorted queue back into the initial main queue
    while (!sortedQueue.empty()) {
        queue.push(sortedQueue.pop());
    }
}

int main() {
    // Queue Testing
    Queue<int> Queue{};

    cout << "--- Queue Test ---" << endl;

    // Creating Queue from an array of integers
    const int arraySize = 10;
    int array[arraySize] = {9, 8, 7, 4, 5, 6, 7, 10, 2, 1};

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

    cout << endl << "--- Reverse Linear Search Test ---" << endl << endl;

    // This should be changed to whatever data type T is in queues, for now integer works
    // RLS Test 1
    int target = 1;
    int targetIndex = reverseLinearSearch<int>(Queue, target, Queue.back(), Queue.size());
    displayRLSResults(target, targetIndex);

    // RLS Test 2
    target = 5;
    targetIndex = reverseLinearSearch<int>(Queue, target, Queue.back(), Queue.size());
    displayRLSResults(target, targetIndex);

    // RLS Test 3
    target = 2;
    targetIndex = reverseLinearSearch<int>(Queue, target, Queue.back(), Queue.size());
    displayRLSResults(target, targetIndex);

    // RLS Test 4 (Testing for error case)
    target = 3;
    targetIndex = reverseLinearSearch<int>(Queue, target, Queue.back(), Queue.size());
    displayRLSResults(target, targetIndex);

    cout << endl << "--- Insertion Search Test ---" << endl << endl;

    // Insertion Sort Test
    insertionSort(Queue);
    Queue.display();

    cout << "--- End of Queue Testing ---" << endl;

    return 0;
}