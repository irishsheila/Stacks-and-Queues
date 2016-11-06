// ===========================================
// Created: September 26, 2016
// Homework Assignment #3 :Stacked Listed List
// Description: Creates and maintains a stack
// through a listed list
// ===========================================

#include <iostream>
#include <string>
#include "HW3-Todo-StackLinkedList.hpp"

using namespace std;


TodoStackLinkedList::TodoStackLinkedList()
{
    //ctor
    stackHead = NULL; //sets the head to NULL
}

/*
 * Function name: isEmpty
 * Purpose: to check if stack is empty
 * @return - true if the stack is empty
*/

bool TodoStackLinkedList::isEmpty()
{
    if (stackHead == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Function name: pop
 * Purpose: to remove a value from the top of a stack
 * @return - none
*/

void TodoStackLinkedList::pop()
{
    if (isEmpty())
    {
        cout << "Stack empty, cannot pop an item."<< endl;
    }
    else
    {
        TodoItem *temp = new TodoItem;
        temp = stackHead;
        stackHead = temp -> next;
        delete temp;
    }
}

/*
 * Function name: push
 * Purpose: to add a value to the top of a stack
 * @param todoItem - a string to add to the top of the stack
 * @return - none
*/

void TodoStackLinkedList::push(string todoItem)
{
    TodoItem *newString = new TodoItem; //puts item on the top of the stack and sets head to point at that item
    newString->todo = todoItem;
    newString->next = stackHead;
    stackHead = newString;
}

/*
 * Function name: peek
 * Purpose: to find the pointer to the first item in the stack
 * @return - a pointer to the stackHead;
*/

TodoItem* TodoStackLinkedList::peek()
{
    if (isEmpty())
    {
        cout << "Stack empty, cannot peek."<< endl;
        return stackHead;
    }
    else
    {
        return stackHead;
    }
}
