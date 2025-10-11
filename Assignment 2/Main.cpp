#include "Main.h"

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Adds a new node to be the new head of the SLL, setting it to be at the front
void SingleLinkedList::pushFront(const string& data = ""){
    // Only occurs if the SLL is empty (Only 1 node, so its both the head and the tail)
    if (empty()) {
        head = tail = new Node(data);
    }

    // Sets the 'next' of the new node to be the previous head, then sets the new head to be the new node
    head = new Node(data, head);

    numItems++;
 }

// Adds a new node to be the new tail of the SLL, setting it to be at the back
void SingleLinkedList::pushBack(const string& data = ""){
    if (empty()) {
        head = tail = new Node(data);
    } else {
        // Sets the 'next' of the current tail to be the new node
        tail->next = new Node(data);
        // Sets the new tail to be 'next' of the previous tail, aka the new node
        tail = tail->next;
    }

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

    // Checks if there's only one node
    if (current->next == nullptr) {
        delete head;
        head = tail = nullptr;
    } else {
        // Moves down the SLL until it reaches a node where the next node's next node is a null pointer
        while (current->next->next != nullptr) {
            current = current->next;
        }
        // Deletes the current tail then sets the current node to be the new tail
        delete current->next;
        current->next = nullptr;
        tail = current;
    }
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
        pushFront(data);
        return;
    }

    // Checks if SLL is empty
    if (empty()) {
        return;
    }

    Node* current = head;

    // Go to index before node at position index to be able to insert at position index
    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) return; // For Insurance

    // Inserts a new node at position index
    Node* newNode = new Node(data, current->next);
    current->next = newNode;

    if (newNode->next == nullptr) {
        tail = newNode;
    }
    numItems++;
}

// Removes a node at position index, then returns true or false based on if the operation succeeded
bool SingleLinkedList::remove(int index){
    // Checks if SLL is empty
    if (empty()) {
        return false;
    }

    // Checks if removal is at the head
    if (index == 0) {
        popFront();
        return true;
    }

    Node* current = head;

    // Go to index before node at position index to be able to remove at position index
    for (int i = 0; i < index - 1 && current != nullptr && current->next != nullptr; i++) {
        current = current->next;
    }

    // Index is out of bounds
    if (current == nullptr || current->next == nullptr) {
        return false;
    }

    // Removes the node at position index
    Node* temp = current->next;

    current->next = temp->next;

    // Resets the tail node to be the current node if the tail node was removed
    if (temp == tail) {
        tail = current;
    }

    delete temp;
    numItems--;
    return true;
}

// Returns the position of the first appearance of an item; returns the size of the SLL if not found
size_t SingleLinkedList::find(const string& data){
    Node* current = head;
    int index = 0;

    // Iterates through the SLL until it finds matching data
    while (current != nullptr) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }

    // Case for when the data is not found in the SLL
    return numItems;
}

bool Stack::isEmpty() const {
        return elements.empty();
    }

// Adds element to top of stack
void Stack::push(int value) {
    elements.push_back(value);
}

// Removes element from top of stack
void Stack::pop() {
    if (isEmpty()) {
        return;
    }
    elements.pop_back();
}

// Gets top element
int Stack::top() {
    if (isEmpty()) {
        return -1;
    }
    return elements.back();
}

// Get size of stack
size_t Stack::size() {
    return elements.size();
}

// Calculate average value of stack elements
double Stack::average() {
    if (isEmpty()) {
        return -1;
    }

    int sum = 0;
    for (int element : elements) {
        sum += element;
    }
    return static_cast<double>(sum) / elements.size(); // For Insurance
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout <<endl;

    // Iterates through the stack and displays each element
    for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
        cout << *it << " ";
    }

    cout << endl << endl;
}

void displaySLL(const SingleLinkedList& SLL) {
    Node* current = SLL.getHead();

    cout << endl;

    for (int i = 0; i < SLL.getNumItems(); i++) {
        cout << current->data << endl;

        current = current->next;
    }

    cout << endl;
}

void displayHead(const SingleLinkedList& SLL) {
    cout << "Head: " << SLL.getHead()->data << endl;
}

void displayTail(const SingleLinkedList& SLL) {
    cout << "Tail: " << SLL.getTail()->data << endl;
}

void displayHeadAndTail(const SingleLinkedList& SLL) {
    displayHead(SLL);
    displayTail(SLL);
}

void displaySLLBundle(const SingleLinkedList& SLL) {
    displaySLL(SLL);
    displayHeadAndTail(SLL);
}

int main() {
    // SLL Testing
    SingleLinkedList SLL{};

    cout << "--- Single Linked List (SLL) Sandbox ---" << endl;

    // Creating SLL from an array of letters
    const int arraySize = 5;
    string arrayOfLetters[arraySize] = {"A", "B", "C", "D", "E"}; // , "F", "G", "H", "I", "J"};

    // Inserts each letter of the array at the head (index 0) of the SLL
    for (const auto & arrayOfLetter : arrayOfLetters) {
        SLL.insert(0, arrayOfLetter);
    }

    // Sets number of items/nodes in SLL to array size
    SLL.setNumItems(arraySize);

    // displaySLLBundle displays the data in the SLL in order, and displays the current head and tail
    displaySLLBundle(SLL);

    // Creates new Front and Back nodes in their respective indexes (index 0 is front, index numItems is back)
    SLL.pushFront("Front");
    SLL.pushBack("Back");

    displaySLLBundle(SLL);

    // Pops the front and back nodes, which are the Front and Back nodes that were created earlier
    SLL.popFront();
    SLL.popBack();

    displaySLLBundle(SLL);

    // Returns/Displays what data is in the front and back
    cout << "Front: " << SLL.front() << endl;
    cout << "Back: " << SLL.back() << endl;

    // Removes the item at index 1 (D in this case) and Index 2 (Since all elements ahead of D are shifted, this removes B)
    SLL.remove(1);
    SLL.remove(2);

    displaySLLBundle(SLL);

    // Finds then displays the index of node with the requested data
    cout << "Element C is at index " << SLL.find("C") << endl;

    // Stack Testing
    Stack myStack;

    cout << endl << "--- Stack (STK) Sandbox ---" << endl;

    // Creating new stack by pushing values
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.display();

    // Removing value at the top of the stack (Last Element)
    int removedValue = myStack.top();
    myStack.pop();
    cout << "Removed element: " << removedValue << endl;
    myStack.display();

    // Displaying top element of the stack
    cout << "Top element: " << myStack.top() << endl;

    // Displaying average value of the stack
    cout << "Average value: " << myStack.average() << endl;

    myStack.push(60);
    myStack.push(70);
    myStack.display();

    // Displaying current size
    cout << "Current stack size: " << myStack.size() << endl;

    // Displaying new average
    cout << "New average: " << myStack.average() << endl;

    // Popping multiple elements
    myStack.pop();
    myStack.pop();
    myStack.display();

    // Final state
    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;
    cout << "Average: " << myStack.average() << endl;

    return 0;
}