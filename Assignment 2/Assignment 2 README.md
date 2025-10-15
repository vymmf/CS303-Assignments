# Assignment 2 Report

**Description:**

Creates Single Linked Lists and Stacks from their respective classes and perform various operations.

**Instructions:**

(If using CLion, make sure it reloads the CMake Project and can read all the CMakeLists.txt files.)


1.) Download the .cpp and .h files from the Assignment 2 folder and have them accessible to one another.

2.) Run the .cpp and .h files in a C++ compiler or an IDE that supports C++.

4.) No User Input is required, program simply tests the creation of Single Linked Lists and Stacks

**Implementation Rundown:**

2 Classes are created for the Single Linked List (SLL) and Stack (STK) data structures.

Single Linked Lists (SLL) has various operations such as:

- Push Front (Adds a new node to the front of the SLL and sets it as the new head)
- Push Back (Adds a new node to the back of the SLL and sets it as the new tail)
- Pop Front (Deletes the node at the front/head, then sets the new head to the node ahead)
- Pop Back (Deletes the node at the back/tail, then sets the new tail to the node before)
- Front (Returns the data in the node at the front/head)
- Front (Returns the data in the node at the back/tail)
- Empty (Checks if the SLL is empty, then returns true or false)
- Insert (Adds a new node at a specified index, also has special cases for index 0 and index 
- Remove (Removes a new node at a specified index, also has special cases for index 0 and index)
- Find (Finds the index of the specified data; returns the size of the SLL if index could not be found)

While Stack (STK) has operations such as:

- IsEmpty (Checks if the STK is empty, then returns true or false)
- Push (Adds element to the top of the STK)
- Pop (Removes element from the top of the STK)
- Top (Returns the element at the top of the STK)
- Size (Returns the size of the STK)
- Average (Returns the average of the STK, assuming the elements are all integers)
- Display (Prints out the STK and each of its elements)

There's also functions that help with displaying specific texts relating to the SLL, such as displaying all the data values in the SLL, and what the head and tail nodes are.

**Input (No Direct User Input):**

Comments are provided to help explain each portion of the code.

<img width="1238" height="775" alt="Screenshot 2025-10-14 at 6 04 44 PM" src="https://github.com/user-attachments/assets/c5333c85-be13-4857-be46-ca689d58bd73" />

<img width="1245" height="774" alt="Screenshot 2025-10-14 at 6 05 02 PM" src="https://github.com/user-attachments/assets/6ede84b6-0ba3-431a-9f01-9b9115f2cd8d" />

<img width="1166" height="701" alt="Screenshot 2025-10-14 at 6 05 13 PM" src="https://github.com/user-attachments/assets/479051c7-a9d6-49bb-bb4f-2a778b65710a" />

**Expected Output:**

<img width="1391" height="812" alt="Screenshot 2025-10-10 at 8 08 33 PM" src="https://github.com/user-attachments/assets/29c7bf20-314d-40de-b61a-5864979b6496" />

<img width="1391" height="818" alt="Screenshot 2025-10-10 at 8 08 51 PM" src="https://github.com/user-attachments/assets/40da987d-48c1-4c90-ad04-787ea207cbf9" />
