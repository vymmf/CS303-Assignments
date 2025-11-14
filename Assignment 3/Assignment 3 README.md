# Assignment 3 Report


**Description:**

Creates Circular Double Linked List Queues from their respective classes and performs various queue-oriented operations. Additionally, Reverse Linear Search and Insertion Sort functions with compatibility with Linked Queues are used and tested in the program.


**Instructions:**

Note: If using CLion, make sure it reloads the CMake Project and can read all the CMakeLists.txt files.

1.) Download the .cpp and .h files from the Assignment 2 folder and have them accessible to one another.

2.) Run the .cpp and .h files in a C++ compiler or an IDE that supports C++.

4.) No User Input is required, program will run and display the results in the console.


**Implementation Rundown:**

A Class and Struct are created for the program, that being a Queue (Circular Double Linked List) and a Node. It should be noted that these are templates, so they use template variables that can be substituted for various data types, such as string, int (used for this assignment), etc.

Each Node has these variables stored in it:

- Data (Whatever information the program or user wants to store in each node, these can be practically any data type, such as strings or ints)
- Next (Memory address of the next node in the Queue)
- Previous (Memory address of the previous node in the Queue)

Queue has various operations such as:

- Push (Adds a new node to the back of the SLL and sets it as the new tail; Additionally sets the next node of the new tail to be the current head and the previous node of the current head to be the new tail)
- Pop (Deletes the node at the front/head, then sets the new head to the node ahead; Additionally sets the previous ndoe of the new head to be the current tail and the next node of the current tail to be the new head)
- Front (Returns the the node at the front/head)
- Back (Returns the the node at the back/tail)
- Empty (Checks if the Queue is empty, then returns true or false)

- Display (Displays all the data values of each node in the queue in order)
- Display Size (Displays the current size of the queue)
- Move To Rear (Moves the front node to the back by popping and then pushing the popped value (Using the operations above))

There are also 2 other functions, Reverse Linear Search and Insertion Sort, that can be used on a Queues to either find the index of an element or sort the queue.

Note: More information about how these functions work are commented within the Assignment 3 .cpp file


**Input (No Direct User Input):**

Comments are provided to help explain each portion of the code.

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 06 59 PM" src="https://github.com/user-attachments/assets/9b6489e1-52e2-48f2-9ab0-e307edca9c2e" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 07 09 PM" src="https://github.com/user-attachments/assets/a1e35219-183c-4b95-87ba-fb9332d902f8" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 07 16 PM" src="https://github.com/user-attachments/assets/64ef1316-e1b6-4689-85ff-8ff6f5272df1" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 07 21 PM" src="https://github.com/user-attachments/assets/f665bdee-cb20-424d-aca3-430235e28401" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 07 25 PM" src="https://github.com/user-attachments/assets/8608561b-e957-45f2-81f3-9fd5e1d67930" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 07 29 PM" src="https://github.com/user-attachments/assets/1e0afb8c-1d38-48c3-be77-351dc1d8d847" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 07 35 PM" src="https://github.com/user-attachments/assets/c63bbf28-bbcb-44f4-ba45-9af27263ef03" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 07 39 PM" src="https://github.com/user-attachments/assets/0d7a1c45-efe1-4d5d-b38e-73c0d795cbd3" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 07 43 PM" src="https://github.com/user-attachments/assets/592d63b3-33a8-44f8-99c4-c9d47b704ad0" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 07 46 PM" src="https://github.com/user-attachments/assets/42374ef0-f227-43df-8cc8-a6616c81cd8b" />


**Expected Output:**

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 08 02 PM" src="https://github.com/user-attachments/assets/d71586d3-2328-4b57-a18f-b24e00b0d5f0" />

<img width="1470" height="956" alt="Screenshot 2025-11-14 at 5 08 09 PM" src="https://github.com/user-attachments/assets/81e6362f-915f-4a6b-8aae-5cb448615e56" />
