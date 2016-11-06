// ===========================================
// Created: September 26, 2016
// Sheila Doherty
// Homework Assignment #3: Queue Array
// Instructor: Elizabeth Boese
// Description: Creates and maintains a queue
// through an array
// ===========================================

#include <string>
#include <iostream>
#include "HW3-Todo-QueueArray.hpp"

using namespace std;

TodoQueueArray::TodoQueueArray()
{
    //ctor
    queueFront = -1;
    queueEnd = -1;

    for (int i; i<MAX_QUEUE_SIZE; i++) //initializing the array
    {
        queue[i] = new TodoItem;
    }
}

/*
 * Function name: isEmpty
 * Purpose: to check if queue is empty
 * @return - true if the queue is empty
*/

bool TodoQueueArray::isEmpty()
{
    if (queueFront == -1 && queueEnd == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Function name: isFull
 * Purpose: to check if queue is full
 * @return - true if the queue is full
*/

bool TodoQueueArray::isFull()
{
    if ((queueFront == 0 && queueEnd == MAX_QUEUE_SIZE - 1) || (queueFront == queueEnd + 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Function name: dequeue
 * Purpose: to remove a value from front top of a queue
 * @return - none
*/

void TodoQueueArray::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue empty, cannot dequeue an item."<< endl;
        return;
    }
    else if (queueFront == queueEnd) //if they are the same, then there is only 1 thing in the array, so now it's empty
    {
        queue[queueFront] = 0;
        queueFront = -1;
        queueEnd = -1;
    }
    else if (queueFront == MAX_QUEUE_SIZE - 1) //if the front of the queue is at the end of the array, the front is now the beginning
    {
        queue[queueFront] = 0;
        queueFront = 0;
    }
    else //otherwise, the front is now the next item in the array
    {
        queue[queueFront] = 0;
        queueFront = queueFront + 1;
    }
}

/*
 * Function name: enqueue
 * Purpose: to add a value to the end of a queue
 * @param todoItem - a string to add to the top of the stack
 * @return - none
*/

void TodoQueueArray::enqueue(string todoItem)
{
    if (isFull())
    {
        cout << "Queue full, cannot add new todo item."<< endl;
        return;
    }
    else if (isEmpty()) //if empty, the front & end are the same & adds to index 0
    {
        queueFront = 0;
        queueEnd = 0;
        queue[queueFront] = new TodoItem;
        queue[queueFront]->todo = todoItem;
    }
    else if (queueEnd == MAX_QUEUE_SIZE - 1) //if the end of the queue is at the end of array, the end of the array is index 0
    {
        queueEnd = 0;
        queue[queueEnd] = new TodoItem;
        queue[queueEnd]->todo = todoItem;
    }
    else //adds value to the next spot of the array
    {
        queueEnd = queueEnd + 1;
        queue[queueEnd] = new TodoItem;
        queue[queueEnd]->todo = todoItem;
    }
}

TodoItem* TodoQueueArray::peek()
{
    if (isEmpty())
    {
        cout << "Queue empty, cannot peek."<< endl;
        TodoItem *pointer = new TodoItem; //makes a pointer to return the pointer of the front of the queue
        pointer = queue[queueFront];
        return pointer;
    }
    else
    {
        TodoItem *pointer = new TodoItem; //makes a pointer to return the pointer of the front of the queue
        pointer = queue[queueFront];
        return pointer;
    }
}

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

