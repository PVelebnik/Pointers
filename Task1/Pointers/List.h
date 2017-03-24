#pragma once
#include <string>

// Initializes list
void StringListInit(char*** list);
// Destroy list and set pointer to NULL.
void StringListDestroy(char*** list);

// Inserts value at the end of the list.
void StringListAdd(char*** list, const char* str);
// Removes all occurrences of str in the list.
void StringListRemove(char** list, const char* str);

int* GetStringListInitPtr(char** list);
//Returns pinter to quantity of initialized strings
int StringListInitialized(char** list);
//Returns pointer to capacity of list
int StringListCapacity(char** list);

//Prints all strings in list
void StringListPrint(char**);

// Returns the index position of the first occurrence of str in the list.
int StringListIndexOf(char** list, const char* str);

void StringListSort(char** list);