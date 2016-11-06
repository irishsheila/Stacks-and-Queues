/*

ALL TESTS PASSED

Commented out for production
*/

#include <iostream>
#include "HW3-Todo-StackLinkedList.hpp"

int main(int argc, char* argv[])
{
	TodoStackLinkedList stackLinkedListTest;
	if (!stackLinkedListTest.isEmpty())
	{
		std::cout << "stack array isEmpty not passing" << std::endl;
		return 1;
	}
	int iterator = 0;

	while (iterator < 500)
	{
		iterator++;
		stackLinkedListTest.push("test" + std::to_string(iterator));
	}
	TodoItem* peekTest = stackLinkedListTest.peek();
	if (peekTest->todo != "test" + std::to_string(iterator))
	{
		std::cout << "stack array peek or push not passing" << std::endl;
		return 1;
	}

	if (stackLinkedListTest.isEmpty())
	{
		std::cout << "stack array isEmpty not passing" << std::endl;
		return 1;
	}

	while (!stackLinkedListTest.isEmpty())
	{
		stackLinkedListTest.pop();
	}


	if (stackLinkedListTest.isEmpty())
	{
		std::cout << "stack array is passing the current build" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "stack array isEmpty is not passing" << std::endl;
		return 1;
	}


}

