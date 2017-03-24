#include <iostream>

#include "List.h"

void StringListInit(char*** list)
{
	void* memory = malloc(5 * sizeof(char*) + 2 * sizeof(int));
	int* const capacity = (int*)memory;
	int* const initialized = capacity + 1;
	*list = (char**)initialized+1;
	*capacity = 5;
	*initialized = 0;
	char** strings = *list;
	for (int i = 0; i < *capacity; i++)
	{
		strings[i] = NULL;
	}
}

void StringListDestroy(char*** list)
{
	int* memory = (int*)*list -2;
	int capacity = *memory;
	char** strings = *list;
	for (int i = 0; i < capacity; i++)
	{
		free(strings[i]);
		strings[i] = NULL;
	}
	free(memory);
	*list = NULL;
}

void StringListAdd(char*** list, const std::string &str)
{
	char* newStr = (char*)malloc(str.length()+ 1);
	newStr[str.length()] = '\0';
	strcpy(newStr, str.c_str());
	int* memory = (int*)*list - 2;
	int capacity = *StringListCapacity(*list);
	int initialized = *StringListInitialized(*list);
	if (capacity == initialized)
	{
		capacity = 2 * initialized;
		void* newMemory = realloc(memory, capacity*sizeof(char*) + 2 * sizeof(int));
		*list = (char**)((int*)newMemory+2);
	}
	(*list)[initialized] = newStr;
	(*StringListInitialized(*list))++;
}

void StringListRemove(char** list, const std::string &str)
{
	int& initialized = *StringListInitialized(list);
	int removed = 0;
	for(int i=0; i<initialized; i++)
	{
		if (strcmp(list[i], str.c_str())==0)
		{
			free(list[i]);
			list[i] = NULL;
			removed++;
			//(*initialized)--;
		}

	}
	int first = 0;
	int last = initialized;
	int result=0;

	//remove_if
	while (first != last) 
	{
		if (list[first]) 
		{
			list[result] = list[first];
			++result;
		}
		++first;
	}

	//erase
	while (result != last)
	{
		list[result] = NULL;
		result++;
	    initialized--;
	}
	
}


int* StringListInitialized(char** list)
{
	return (int*)list - 1;
}

int* StringListCapacity(char** list)
{
	return (int*)list - 2;
}

void StringListPrint(char** list)
{
	for (int i = 0; i < *StringListInitialized(list); i++)
	{
		std::cout << list[i] <<std::endl;
	}
}

int StringListIndexOf(char** list, const char* str)
{
	for(int i=0;i<*StringListInitialized(list);i++)
	{
		if (strcmp(list[i], str) == 0)
		{
			return i;
		}
	}
	return -1;
}

void StringListSort(char** list)
{
	const int& initialized = *StringListInitialized(list);
	char* temp = NULL;
	for (int i = 0; i < initialized; i++)
	{
		for (int j = i + 1; j <initialized; j++)
		{
			if (strcmp(list[i], list[j]) > 0)
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}