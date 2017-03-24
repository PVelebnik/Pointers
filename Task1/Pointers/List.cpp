#include <iostream>

#include "List.h"

void StringListInit(char*** list)
{
	void* memory = malloc(5 * sizeof(char*) + 2 * sizeof(int));
	int* const capacity = (int*)memory;
	int* const initialized = capacity + 1;
	*list = (char**)initialized + 1;
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

void StringListAdd(char*** list, const char* str)
{
	char* newStr = (char*)malloc(strlen(str)+1);
	strcpy(newStr, str);
	int* memory = (int*)*list - 2;
	int capacity = StringListCapacity(*list);
	int initialized = StringListInitialized(*list);
	if (capacity == initialized)
	{
		capacity = 2 * initialized;
		void* newMemory = realloc(memory, capacity*sizeof(char*) + 2 * sizeof(int));
		*list = (char**)((int*)newMemory+2);
	}
	(*list)[initialized] = newStr;
	(*GetStringListInitPtr(*list))++;
}

void StringListRemove(char** list, const char* str)
{
	int& initialized = *GetStringListInitPtr(list);
	for(int i=0; i<initialized; i++)
	{
		if (strcmp(list[i], str)==0)
		{
			free(list[i]);
			list[i] = NULL;
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

int* GetStringListInitPtr(char** list)
{
	return (int*)list - 1;
}

int StringListInitialized(char** list)
{
	return *((int*)list - 1);
}

int StringListCapacity(char** list)
{
	return *((int*)list - 2);
}

void StringListPrint(char** list)
{
	for (int i = 0; i < StringListInitialized(list); i++)
	{
		std::cout << list[i] <<std::endl;
	}
}

int StringListIndexOf(char** list, const char* str)
{
	for(int i = 0; i<StringListInitialized(list); i++)
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
	const int initialized = *GetStringListInitPtr(list);
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