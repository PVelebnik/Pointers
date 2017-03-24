#include <iostream>
#include "List.h"


#define ARE_EQ( x, y) \
 if (x == y) std::cout << "Passed" <<std::endl; else { std::cout<< "Failed " <<x <<" != " << y<<std::endl;  return;} 

#define ARE_EQ_CSTR( x, y) \
 if (strcmp(x, y) == 0) std::cout << "Passed" <<std::endl; else { std::cout<< "Failed " <<x <<" != " << y<<std::endl;  return;} 

void testListInit()
{
	std::cout << "testListInit:" << std::endl;
	char** testList = NULL;
	StringListInit(&testList);

	ARE_EQ(*StringListInitialized(testList), 0)

    std::string str = "first";
	StringListAdd(&testList, str);

	ARE_EQ_CSTR(testList[0], str.c_str())
    ARE_EQ(*StringListInitialized(testList), 1)

	StringListDestroy(&testList);
	std::cout << std::endl;
}

void testListDestroy()
{
	std::cout << "testListDestroy:" << std::endl;
	char** testList = NULL;
	StringListInit(&testList);

	std::string str = "first";
	StringListAdd(&testList, str);
	ARE_EQ(testList[0], str)

	StringListDestroy(&testList);
	ARE_EQ(testList, NULL)

	std::cout << std::endl;
}

void testListAdd()
{
	std::cout << "testListAdd:" << std::endl;
	char** testList = NULL;
	StringListInit(&testList);

	std::string str = "first";
	StringListAdd(&testList, str);

	ARE_EQ(*StringListInitialized(testList), 1)
	ARE_EQ_CSTR(testList[0], str.c_str())
	StringListAdd(&testList, str);
	ARE_EQ(*StringListInitialized(testList), 2)

	StringListDestroy(&testList);
	std::cout << std::endl;
}

void testListRemove()
{
	std::cout << "testListRemove:" << std::endl;
	char** testList = NULL;
	StringListInit(&testList);
	std::string str = "foo";
	std::string str2 = "bar";
	std::string str3 = "foobar";

	StringListAdd(&testList, str);
	StringListAdd(&testList, str2);
	StringListAdd(&testList, str3);

	StringListRemove(testList, str);
	ARE_EQ_CSTR(testList[0], str2.c_str())

	StringListRemove(testList, str2);
	ARE_EQ_CSTR(testList[0], str3.c_str())

		StringListDestroy(&testList);
	std::cout << std::endl;
}

void testInitialized()
{
	std::cout << "testInitialized:" << std::endl;
	char** testList = NULL;
	StringListInit(&testList);
	ARE_EQ(*StringListInitialized(testList), 0)
	
	std::string str = "efgh";
	StringListAdd(&testList, str);
	ARE_EQ(*StringListInitialized(testList), 1)

	StringListDestroy(&testList);
	std::cout << std::endl;
}

void testCapacity()
{
	std::cout << "testCapacity:" << std::endl;
	char** testList = NULL;
	StringListInit(&testList);
	ARE_EQ(*StringListCapacity(testList), 5)
	StringListDestroy(&testList);
	std::cout << std::endl;
}

void testIndexOf()
{
	std::cout << "testIndexOf:" << std::endl;
	char** testList = NULL;
	StringListInit(&testList);

	std::string str = "foo";
	std::string str2 = "bar";
	std::string str3 = "bar";

	ARE_EQ(StringListIndexOf(testList, str3.c_str()), -1)

	StringListAdd(&testList, str);
	StringListAdd(&testList, str2);
	StringListAdd(&testList, str3);


	ARE_EQ(StringListIndexOf(testList, str3.c_str()), 1)

	StringListDestroy(&testList);
	std::cout << std::endl;
}

void testSort()
{
	std::cout << "testSort:" << std::endl;
	char** testList = NULL;
	StringListInit(&testList);

	std::string str = "efgh";
	std::string str2 = "jklm";
	std::string str3 = "abcde";

	StringListAdd(&testList, str);
	StringListAdd(&testList, str2);
	StringListAdd(&testList, str3);

	StringListSort(testList);

	ARE_EQ_CSTR(testList[0], str3.c_str())
	ARE_EQ_CSTR(testList[1], str.c_str())
	ARE_EQ_CSTR(testList[2], str2.c_str())

	StringListDestroy(&testList);
	std::cout << std::endl;
}

void runTests()
{
	testListInit();
	testListDestroy();
	testListAdd();
	testListRemove();
	testInitialized();
	testCapacity();
	testIndexOf();
	testSort();
}