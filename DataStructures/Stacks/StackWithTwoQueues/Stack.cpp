#include <iostream>
#include<queue>
#include <list>
#include"Stack.h"

template <typename T>
Stack<T>::Stack()
{
    Q1 = new std::queue<T,std::list<T>>;
    Q2 = new std::queue<T,std::list<T>>;

}

//overloaded  constructor for list of stack elements
//delegate initialization to default constructor
template <typename T>
Stack<T>::Stack(std::initializer_list<T> l) : Stack()
{
    //push elements from initializer list into Q1 with stack LIFO behavior.
    for(auto i = l.begin(); i != l.end() ; i++)
        push_top(*i);

}

//costly push in stack and non-costly pop: push O(N) and pop O(1)

/**
* pre condition: stack is initialized.
* post condition:stack has copy of element.
* size of stack increased by one.
*/
template <typename T>
bool Stack<T>::push_top(const T& element)
{
    //for first element of the stack
    if (Q1-> empty())
    {
        Q1->push(element);
    }
    else
    {
        //if Q1 has more than one element, move all elements to Q2
        for (; !Q1-> empty(); Q1->pop())
        {

            Q2->push(Q1->front());

        }
        //push new element in the empty Q1 in order to achieve LIFO stack behavior.
        Q1->push(element);

        //move all elements back from Q2 to Q1
        for (; !Q2-> empty(); Q2->pop())
        {

            Q1->push(Q2->front());

        }
    }

    return true;

}
/**
* pre condition: stack is initialized.
* post condition:return 0 if stack is empty
* if not empty,top element of the stack got removed and the function return 1.
* size of stack decreased by one.
*/
template <typename T>
bool Stack<T>::pop_top ()
{
    if (Q1->empty()) return 0;
    Q1-> pop();
    return 1;
}

/**
* pre condition: stack is initialized.
* post condition:return 0 if stack is empty
* if not empty, top element is returned inside element reference and the function return 1
*/
template <typename T>
bool Stack<T>::top (T& element)
{
    if (Q1->empty()) return 0;
    element = Q1->front();
    return 1;
}

/**
* pre condition: stack is initialized.
* post condition:return true if stack is empty and false if it's not.
*/
template <typename T>
bool Stack<T>::empty() const
{

    return !Q1->empty();
}

/**
* pre condition: stack is initialized.
* post condition: if stack is not empty, it will print stack elements.
* if stack is empty, it won't do anything.
*/
template <typename T>
void Stack<T>::print_stack()
{
    for (; !Q1-> empty(); Q1->pop())
    {
        T current_element { Q1->front()};
        std::cout<< current_element<< " ";
        //to move elements from Q1 to Q2
        Q2->push(current_element);
    }

    for (; !Q2-> empty(); Q2->pop())
    {
        //to move elements back from Q2 to Q1
        Q1->push(Q2->front());

    }
}

/**
* pre condition: stack is initialized.
* post condition: returns number of element in the stack.
* if stack is empty, it will return 0.
*/
template <typename T>
size_t Stack<T>::size () const
{
    return Q1->size();
}

template <typename T>
Stack<T>::~Stack()
{
    delete Q1;
    delete Q2;
}

/*
// costly popping, non-costly pushing
template <typename T>
bool Stack<T>::push_top(const T& element)
{
if (!empty()) Q1->push(element);
}


//works with special cases: no elements, one element in the Queue, two elements
template <typename T>
bool Stack<T>::pop_top ()
{
    if(!empty())
    {
        //loop over all Q1 elements except last element
        for (int i{0} ;  i < size()-1; ++i )
        {
            T current_element  = Q1->front();
            Q2->push(current_element);
            Q1->pop();

        }
        //pop last element from Q1.
        Q1.pop();

        //retrieve elements back from Q1 to Q2
        for (; !Q2->empty(); Q2->pop())
        {
            current_element  =Q2->front();
            Q1->push(current_element);
        }
    }
}
*/
