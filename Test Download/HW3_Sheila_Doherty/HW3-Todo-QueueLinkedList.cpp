// ===========================================
// Created: September 26, 2016
// Sheila Doherty
// Homework Assignment #3: Queued Listed List
// Instructor: Elizabeth Boese
// Description: Creates and maintains a queue
// through a listed list
// ===========================================

#include <iostream>
#include <string>
#include "HW3-Todo-QueueLinkedList.hpp"

using namespace std;


TodoQueueLinkedList::TodoQueueLinkedList()
{
    //ctor
    queueFront = NULL; //sets the head to NULL
    queueEnd = NULL;
}

/*
 * Function name: isEmpty
 * Purpose: to check if queue is empty
 * @return - true if the queue is empty
*/

bool TodoQueueLinkedList::isEmpty()
{
    if (queueFront == NULL)
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
 * Purpose: removes a value from the front of the queue
 * @return - none
*/

void TodoQueueLinkedList::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue empty, cannot dequeue an item."<< endl;
    }
    else
    {
        TodoItem *temp = new TodoItem;
        temp = queueFront; //copies the head pointer
        queueFront = queueFront->next; //sets the head to next item on the list
        delete temp; //clears memory
    }
}

/*
 * Function name: enqueue
 * Purpose: to add a value to end of a queue
 * @param todoItem - a string to add to the back of a queue
 * @return - none
*/

void TodoQueueLinkedList::enqueue(string todoItem)
{
    TodoItem *newString = new TodoItem;
    newString->todo = todoItem; //sets string to todo
    newString->next = NULL; //sets next to NULL, end of list
    if (queueFront == NULL) //if it's the first item on the list
    {
        queueFront = newString; //the front now points to newString
    }
    else
    {
        queueEnd->next = newString; //otherwise, the last item now points to newString
    }
    queueEnd = newString; //sets the last item to the new item
}

/*
 * Function name: peek
 * Purpose: to find the pointer to the first item in the stack
 * @return - a pointer to the queueFront;
*/

TodoItem* TodoQueueLinkedList::peek()
{
    if (isEmpty())
    {
        cout << "Stack empty, cannot peek."<< endl;
        return NULL;
    }
    else
    {
        return queueFront; //returns the pointer to the first item on the list
    }
}

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
