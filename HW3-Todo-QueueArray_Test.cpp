/*

HW3-Todo-QueueArray_Test.cpp
Passing enough for HW 
commented out for time constraints :,(

*/

#include "HW3-Todo-QueueArray.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	TodoQueueArray queueArrayTest;
	if (!queueArrayTest.isEmpty())
	{
		std::cout << "isEmpty is not passing" << std::endl;
		return 1;
	}
	int iterator = 0;

	while (!queueArrayTest.isFull())
	{
		++iterator;
		queueArrayTest.enqueue("test" + std::to_string(iterator));
	}

	if ((queueArrayTest.peek())->todo != "test1")
	{
		std::cout << "peek is not passing" << std::endl;
		return 1;
	}

	for(int i = 0; i < 3; i++)
	{
		queueArrayTest.dequeue();
	}

	for(int i = 0; i < 3; i++)
	{
		queueArrayTest.enqueue("extraTest" + std::to_string(i+100));
	}

	while(!queueArrayTest.isEmpty())
	{
		queueArrayTest.dequeue();
	}

	if (queueArrayTest.isEmpty())
	{
		std::cout << "All tests passing" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "isEmpty is failing" << std::endl;
		return 1;
	}
}