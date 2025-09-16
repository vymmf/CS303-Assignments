#ifndef CS303_ASSIGNMENTS_MAIN_H
#define CS303_ASSIGNMENTS_MAIN_H

#include <iostream>

using namespace std;

int countElements(const string& fileName);

int processArray(const string& fileName, int*& array);

void displayArray(int*& array, int& arraySize, const int rowSize);

int findValue(int target, int*& array, int& arraySize);

void modifyValue(int index, int newValue, int*& array, int& arraySize);

void addValue(int value, int*& array, int& arraySize, int& capacity);

void removeValue(int index, int*& array, int& arraySize);

void displayOptions();

int getUserInput(int version, int& arraySize);

bool executeOption(int choice, int*& array, int& arraySize, int capacity, const int rowSize);

int main();

#endif //CS303_ASSIGNMENTS_MAIN_H
