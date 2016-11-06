/*


ALL TESTS PASSED

Removed for production

*/

#include"HW3-Todo-StackArray.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	TodoStackArray stackArrayTest;
	if(!stackArrayTest.isEmpty())
	{
		std::cout << "stack array isEmpty not passing" << std::endl;
		return 1;
	}
	int iterator = 0;

	while(!stackArrayTest.isFull())
	{
		iterator++;
		stackArrayTest.push("test" + iterator);
	}
	TodoItem* peekTest = stackArrayTest.peek();
	if(peekTest->todo != "test" + iterator)
	{
		std::cout << "stack array peek or push not passing" << std::endl;
		return 1;
	}
	
	if(stackArrayTest.isEmpty())
	{
		std::cout << "stack array isEmpty not passing" << std::endl;
		return 1;
	}

	while (!stackArrayTest.isEmpty())
	{
		stackArrayTest.pop();
	}

	
	if(stackArrayTest.isEmpty())
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