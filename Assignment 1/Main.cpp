#include "Main.h"
#include <iostream>
#include <fstream>

using namespace std;

// Count number of elements in an input file
int countElements(const string& fileName)
{
    ifstream file(fileName);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + fileName);
    }

    int count = 0;
    int value;

    // Counts amount of elements to set size of array
    while (file >> value)
    {
        count++;
    }

    return count;
}


// Processes an array from an input file
int processArray(const string& fileName, int*& array)
{
    // Opens the file; if it can't be open, throws an error
    ifstream file(fileName);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + fileName);
    }

    int count = countElements(fileName);
    int index = 0;

    array = new int[count];

    // Sets each individual element in the file as a value in an index in the array
    while (file >> array[index])
    {
        // cout << array[index] << endl;
        index++;
    }

    // cout << "Count: " << count << endl;

    return count;
}

void displayArray(int*& array, int& arraySize, const int rowSize)
{
    cout << "Displaying Array:" << endl << endl;
    int columnNum = 1;
    // (Unused) Finds the integer with the most amount of digit places
    // int highestNumDigits = to_string(abs(array[arraySize - 1])).length();

    // Displays all the values in the array in a group/row of the rowSize number
    for (int i = 0 ; i < arraySize ; i++)
    {
        cout << setw(3) << array[i] << " ";
        if (columnNum == rowSize)
        {
            cout << endl;
            columnNum = 0;
        }
        columnNum++;
    }
}

// Assuming the array is already sorted
int findValue(int target, int*& array, int& arraySize)
{
    for (int i = 0 ; i < arraySize ; i++)
    {
        if (array[i] == target)
        {
            // returns index
            return i;
        }
    }
    // Slight error handling for when value can't be found
    cout << "Value could not be found in the array." << endl;
    return -1;
}

void modifyValue(int index, int newValue, int*& array, int& arraySize)
{
    if (index < 0 || index >= arraySize)
    {
        throw out_of_range("Index out of bounds");
    }
    // Saves old value and sets the index to the new value
    int oldValue = array[index];

    array[index] = newValue;

    // Displays the modified index and the old and new values
    cout << "Modified index " << index << endl
    << "Old Value: " << oldValue << endl
    << "New Value: " << newValue << endl;
}

// Adds the user inputted value to the end of the array
void addValue(int value, int*& array, int& arraySize, int& capacity)
{
    int* newArray = nullptr;

    // Checks if array capacity needs to be increased
    if (arraySize >= capacity)
    {
        int newCapacity = capacity * 2;
        try
        {
            newArray = new int[newCapacity];
        }
        catch (const bad_alloc& e)
        {
            throw bad_alloc();
        }


        // Copies elements from old array into new array
        for (int i = 0; i < arraySize; i++)
        {
            newArray[i] = array[i];
        }

        // Frees old memory + updates pointers
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

    // Adds new value
    array[arraySize] = value;
    arraySize++;
}

// Removes a value based on index of an array by shifting all values in front of it back an index
void removeValue(int index, int*& array, int& arraySize)
{
    // Shifts all values in the array back by 1 index, starting from the user inputted index
    for (int i = index ; i < (arraySize - 1) ; i++)
    {
        array[i] = array[i + 1];
    }

    // Decrements array size so the leftover duplicate value at the end is not a part of the array
    arraySize--;
}

// Displays the available operations to the user
void displayOptions()
{
    cout << "Array Operations:" << endl
    << "1.) Display Array" << endl
    << "2.) Find Value" << endl
    << "3.) Modify Value" << endl
    << "4.) Add Value" << endl
    << "5.) Remove Value" << endl
    << "6.) Quit" << endl;
}

// Has 3 versions for user input, 1 where the integer needs to be between 1 and 6, another that checks if the value is valid as an index, and another that accepts any integer
int getUserInput(int version, int& arraySize)
{
    int choice;

    while (true)
    {
        cout << endl << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        // Error handling for user input, only valid inputs will allow the function to return a value
        // Checks if input is between 1 and 6
        if (version == 1 && (cin.fail() || (choice < 1 || choice > 6)))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a valid integer (1 - 6).";
        }
        // Checks if input is between 0 and array size minus 1
        else if (version == 2 && (cin.fail() || (choice < 0 || choice > (arraySize - 1))))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a valid index.";
        }
        // Checks if input is an integer
        else if (version == 3 && (cin.fail()))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a valid integer.";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

// Executes an operation based on the user's input
bool executeOption(int choice, int*& array, int& arraySize, int capacity, const int rowSize)
{
    switch(choice)
    {
        case 1: // Display Array
        {
            displayArray(array, arraySize, rowSize);
            cout << endl;
            return true;
        }

        case 2: // Find Value
        {
            cout << "Please input the value you want to find." << endl;
            int target = getUserInput(3, arraySize);
            int index = findValue(target, array, arraySize);

            if (index > 0)
            {
                cout << "Found value " << target << " at index " << index << "." << endl;
            }

            cout << endl;
            return true;
        }

        case 3: // Modify Value
        {
            try
            {
                cout << "Please input the index you want to modify." << endl;
                int index = getUserInput(2, arraySize);

                cout << "Please input the new value of the index." << endl;
                int value = getUserInput(3, arraySize);

                modifyValue(index, value, array, arraySize);
            }
            catch (const out_of_range& e)
            {
                cout << "Error: " << e.what() << endl;
                cout << "Please enter a valid index between 0 and " << (arraySize - 1) << endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }

            cout << endl;
            return true;
        }

        case 4: // Add Value
        {
            try
            {
                cout << "Please input the value you want to add." << endl;
                int value = getUserInput(3, arraySize);

                addValue(value, array, arraySize, capacity);

                cout << "Value " << value << " added successfully." << endl;
                cout << "New array size: " << arraySize << ", Capacity: " << capacity << endl;
            }
            catch (const bad_alloc& e)
            {
                cout << "Memory allocation failed. Cannot add new value." << endl;
                cout << "Error: " << e.what() << endl;
            }
            catch (const exception& e)
            {
                cout << "Unexpected error during addition: " << e.what() << endl;
            }

            return true;
        }

        case 5: // Remove Value
        {
            cout << "Please input the index of the value you want to remove." << endl;
            int index = getUserInput(2, arraySize);
            int value = array[index];

            removeValue(index, array, arraySize);

            cout << "Value " << value << " at index " << index << " removed successfully." << endl;

            return true;
        }

        case 6: // Quit
        {
            return false;
        }

        default: // default case should never trigger normally
            cout << "Something unexpected happened" << endl;
            return true;
            // throw invalid_argument("Invalid input! Please enter a valid integer.");
    }
}

int main()
{
    // For testing purposes
//    const int arraySize = 5;
//    int* originalArray = new int[arraySize];
//    createArray(originalArray, arraySize);
//
//    delete[] originalArray;

    string inputFile = "A1input.txt";
    int* originalArray = nullptr;
    int arraySize;
    int capacity;
    int rowSize = 10;
    int choice;
    bool loop = true;

    cout << "Welcome to the Dynamic Array Program." << endl << endl;

    try
    {
        arraySize = processArray(inputFile, originalArray);
        capacity = arraySize;
    }
    // Generic error handling exception
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    cout << "Input file successfully read, initialized sample array." << endl << endl;

    // Main program loop; ends when the user chooses 6.) Quit
    while (loop)
    {
        displayOptions();

        try
        {
            choice = getUserInput(1, arraySize);
        }
        catch (const invalid_argument& e)
        {
            cerr << "Invalid Argument: " << e.what() << std::endl;
            return 1;
        }
        catch (const exception& e)
        {
            cerr << "Error: " << e.what() << std::endl;
            return 1;
        }

        loop = executeOption(choice, originalArray, arraySize, capacity, rowSize);
    }

    cout << "Thank you for using this program.";

    // Deleting array as to stop a memory leak
    delete[] originalArray;
    return 0;
}