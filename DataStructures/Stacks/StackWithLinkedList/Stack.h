#ifndef STACK_H
#define STACK_H

#include "StackNode.h"

template <typename T>
class Stack
{
public:
    Stack(): top{nullptr}, count{0}
    {

    }
    Stack(const T& data)
    {
        StackNode<T> *new_element = new StackNode<T> ();
        new_element-> data = data;
        top = new_element;
        count = 1;

    }
    bool is_full()
    {
        return (0);
    }

    bool is_empty()
    {
        return (count == 0);
    }

    void  push (const T& element)
    {
        //pre: initialized
        //post: one element on top of stack
        StackNode<T> *new_node = new StackNode<T> ();
        new_node-> data = element;
        new_node-> next = top;
        if  (top != nullptr)
        {

            top-> back =  new_node;

        }
        top = new_node;
        ++count;
    }

    void pop (T& element)
    {
        //pre: initialized and not empty
        //post: top element of stack is deleted

        StackNode<T> *temp (top);
        element  = temp -> data;
        top = temp -> next;
        if  (top!= nullptr)
        {

            top-> back =  nullptr;

        }

        delete temp;
        --count;
    }

    void stack_top (T& element)
    {
        //pre: stack initialized and not empty
        //post: return top element without deleting it
        element  =  top -> data;
    }

    void clear()
    {
//pre: stack initialized and not empty
//post:stack is empty
        StackNode<T> *temp;
        while (count != 0)
        {
            temp = top;
            top = temp-> next;
            if(top != nullptr)
            {

                top->back= nullptr;

            }

            delete temp;
            --count;

        }
    }

    int length()
    {
        return count;
    }
    int size()
    {
        return count;
    }

    void traverse (void (*func) (const T& stack_element))
    {
//pre:stack initialized and not empty
//post: send every element of stack as a parameter to the function specified
        StackNode<T> *current {top};
        while (current != nullptr)
        {
            T element = current -> data;
            func(element);
            current= current -> next;

        }
    }


    virtual ~Stack()
    {
        clear();
    }

private:
    StackNode<T> *top;
    int count;

};

#endif // STACK_H
