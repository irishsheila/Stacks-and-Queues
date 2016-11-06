// ===========================================
// Created: September 26, 2016
// Sheila Doherty
// Homework Assignment #3: Stack Array
// Instructor: Elizabeth Boese
// Description: Creates and maintains a stack
// through an array
// ===========================================

#include <string>
#include <iostream>
#include "HW3-Todo-StackArray.hpp"

using namespace std;

TodoStackArray::TodoStackArray()
{
    //ctor
    stackTop = -1; //sets the stack to 0

    for (int i; i<MAX_STACK_SIZE; i++) //initializes array
    {
        stack[i] = new TodoItem;
    }
}

/*
 * Function name: isEmpty
 * Purpose: to check if stack is empty
 * @return - true if the stack is empty
*/

bool TodoStackArray::isEmpty()
{
    if (stackTop == -1)
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
 * Purpose: to check if stack is empty
 * @return - true if the stack is empty
*/

bool TodoStackArray::isFull()
{
    if (stackTop == MAX_STACK_SIZE - 1)
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

void TodoStackArray::pop()
{
    if (isEmpty())
    {
        cout << "Stack empty, cannot pop an item."<< endl;
    }
    else //takes 1 off the top of the stack
    {
        stackTop = stackTop - 1;
    }
}

/*
 * Function name: push
 * Purpose: to add a value to the top of a stack
 * @param todoItem - a string to add to the top of the stack
 * @return - none
*/

void TodoStackArray::push(string todoItem)
{
    if (isFull())
    {
        cout << "Stack full, cannot add new todo item."<< endl;
    }
    else
    {
        stackTop = stackTop +1;
        stack[stackTop] = new TodoItem;
        stack[stackTop]->todo = todoItem;
    }
}

TodoItem* TodoStackArray::peek()
{
    if (isEmpty())
    {
        cout << "Stack empty, cannot peek."<< endl;
        TodoItem *pointer = new TodoItem;
        pointer = stack[stackTop];
        return pointer;
    }
    else
    {
        TodoItem *pointer = new TodoItem;
        pointer = stack[stackTop];
        return pointer;
    }
}
