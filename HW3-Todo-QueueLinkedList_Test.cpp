/* 

HW3-Todo-QueueLinkedList_Test.cpp
ALL TESTS PASSING
commented out for production
*/
#include "HW3-Todo-QueueLinkedList.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	TodoQueueLinkedList queueLinkedListTest;
	if(!queueLinkedListTest.isEmpty())
	{
		std::cout << "isEmpty is not passing" << std::endl;
		return 1;
	}
	int iterator = 0;

	while(iterator < 500)
	{
		++iterator;
		queueLinkedListTest.enqueue("test" + std::to_string(iterator));
	}

	if (queueLinkedListTest.peek()->todo != "test1")
	{
		std::cout << "peek is not passing" << std::endl ;
		return 1;
	}

	while(!queueLinkedListTest.isEmpty())
	{
		queueLinkedListTest.dequeue();
	}

	if(queueLinkedListTest.isEmpty())
	{
		std::cout <<  "All tests passing" << std::endl ;
		return 0;
	} else
	{
		std::cout << "isEmpty is failing" << std::endl;
		return 1;
	}
}

