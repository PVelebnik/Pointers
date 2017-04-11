#include <iostream>
#include "List.h"


#define ARE_EQ( x, y) \
 if (x == y) std::cout << "Passed" <<std::endl; else { std::cout<< "Failed " <<x <<" != " << y<<std::endl;  return;} 

#define ARE_EQ_CSTR( x, y) \
 if (strcmp(x, y) == 0) std::cout << "Passed" <<std::endl; else { std::cout<< "Failed " <<x <<" != " << y<<std::endl;  return;} 

void TestListInit()
{
	std::cout << "TestListInit:" << std::endl;
	char** test_list = NULL;
	StringListInit(&test_list);

	ARE_EQ(StringListInitialized(test_list), 0)

	char* str = "first";
	StringListAdd(&test_list, str);

	ARE_EQ_CSTR(test_list[0], str)
    ARE_EQ(StringListInitialized(test_list), 1)

	StringListDestroy(&test_list);
	std::cout << std::endl;
}

void TestListDestroy()
{
	std::cout << "TestListDestroy:" << std::endl;
	char** test_list = NULL;
	StringListInit(&test_list);

	char* str = "first";
	StringListAdd(&test_list, str);
	ARE_EQ_CSTR(test_list[0], str)

	StringListDestroy(&test_list);
	ARE_EQ(test_list, NULL)

	std::cout << std::endl;
}


//check realloc
//strings` pointers did not change addresses
//pointer testList have been changed
void TestListAdd()
{
	std::cout << "TestListAdd:" << std::endl;
	char** test_list = NULL;
	StringListInit(&test_list);

	char* str = "first";
	StringListAdd(&test_list, str);

	ARE_EQ(StringListInitialized(test_list), 1)
	ARE_EQ_CSTR(test_list[0], str)
	StringListAdd(&test_list, str);
	ARE_EQ(StringListInitialized(test_list), 2)

	StringListDestroy(&test_list);
	std::cout << std::endl;
}

void TestListRemove()
{
	std::cout << "TestListRemove:" << std::endl;
	char** test_list = NULL;
	StringListInit(&test_list);
	char* str = "foo";
	char*str2 = "bar";
	char*str3 = "foobar";

	StringListAdd(&test_list, str);
	StringListAdd(&test_list, str2);
	StringListAdd(&test_list, str3);

	StringListRemove(test_list, str);
	ARE_EQ_CSTR(test_list[0], str2)

	StringListRemove(test_list, str2);
	ARE_EQ_CSTR(test_list[0], str3)

		StringListDestroy(&test_list);
	std::cout << std::endl;
}

void TestInitialized()
{
	std::cout << "TestInitialized:" << std::endl;
	char** test_list = NULL;
	StringListInit(&test_list);
	ARE_EQ(StringListInitialized(test_list), 0)
	
	char* str = "efgh";
	StringListAdd(&test_list, str);
	ARE_EQ(StringListInitialized(test_list), 1)

	StringListDestroy(&test_list);
	std::cout << std::endl;
}

void TestCapacity()
{
	std::cout << "TestCapacity:" << std::endl;
	char** test_list = NULL;
	StringListInit(&test_list);
	ARE_EQ(StringListCapacity(test_list), 5)
	StringListDestroy(&test_list);
	std::cout << std::endl;
}

void TestIndexOf()
{
	std::cout << "TestIndexOf:" << std::endl;
	char** test_list = NULL;
	StringListInit(&test_list);

	char* str = "foo";
	char* str2 = "bar";
	char* str3 = "bar";

	ARE_EQ(StringListIndexOf(test_list, str3), -1)

	StringListAdd(&test_list, str);
	StringListAdd(&test_list, str2);
	StringListAdd(&test_list, str3);


	ARE_EQ(StringListIndexOf(test_list, str3), 1)

	StringListDestroy(&test_list);
	std::cout << std::endl;
}

void TestSort()
{
	std::cout << "TestSort:" << std::endl;
	char** test_list = NULL;
	StringListInit(&test_list);

	char* str = "efgh";
	char* str2 = "jklm";
	char* str3 = "abcde";

	StringListAdd(&test_list, str);
	StringListAdd(&test_list, str2);
	StringListAdd(&test_list, str3);

	StringListSort(test_list);

	ARE_EQ_CSTR(test_list[0], str3)
	ARE_EQ_CSTR(test_list[1], str)
	ARE_EQ_CSTR(test_list[2], str2)

	StringListDestroy(&test_list);
	std::cout << std::endl;
}

void RunTests()
{
	TestListInit();
	TestListDestroy();
	TestListAdd();
	TestListRemove();
	TestInitialized();
	TestCapacity();
	TestIndexOf();
	TestSort();
}