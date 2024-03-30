#include<iostream>
#include<stack>
#include<list>
#include "Queue.h"

template<typename T>
Queue<T>::Queue()
{

    S1 = new std::stack<T,std::list<T>>;
    S2 = new std::stack<T,std::list<T>>;
}

//Costly push and non-costly pop

//overloaded  constructor for list of Queue elements
//delegate initialization to default constructor
template<typename T>
Queue<T>::Queue(std::initializer_list<T> l):Queue()
{

    //push elements from initializer list into Q1 with stack LIFO behavior.
    for(auto i = l.begin(); i != l.end() ; i++)
        push_front(*i);
}

/**
* pre condition: Queue is initialized.
* post condition:Queue has copy of element.
* size of Queue increased by one.
*/
template<typename T>
bool Queue<T>::push_front(const T& element)
{
    //for first element of the Queue
    if (S1->empty())
    {
        S1->push(element);
    }
    else
    {
//if S1 has more than one element, move all elements to S2
        for(; !S1->empty(); S1->pop())
        {
            S2.push(S1.top());

        }
        //push new element in the empty S1.
        S1->push(element);

        //move all elements back from S2 to S1
        for (; !S2->empty(); S2->pop())
        {
            S1.push (S2->top());
        }

    }

    return true;
}

/**
* pre condition: Queue is initialized.
* post condition:return 0 if Queue is empty
* if not empty,front element of the Queue got removed and the function return 1.
* size of Queue decreased by one.
*/
template<typename T>
bool Queue<T>::pop_back()
{
    if (S1->empty()) return 0;
    S1-> pop();
    return 1;

}

/**
* pre condition: Queue is initialized.
* post condition:return true if Queue is empty and false if it's not.
*/
template<typename T>
bool Queue<T>::empty() const
{
    return !S1->empty();
}

/**
* pre condition: Queue is initialized.
* post condition:return 0 if Queue is empty
* if not empty, front element is returned inside element reference and the function return 1
*/
template<typename T>
bool Queue<T>::front(T& element)
{
    if (S1->empty()) return 0;
    element = S1->front();
    return 1;
}

/**
* pre condition: Queue is initialized.
* post condition: returns number of element in the Queue.
* if Queue is empty, it will return 0.
*/
template<typename T>
size_t Queue<T>::size () const
{
    return S1->size();
}


/**
* pre condition: Queue is initialized.
* post condition: if Queue is not empty, it will print Queue elements.
* if Queue is empty, it won't do anything.
*/
template<typename T>
void Queue<T>::print_Q()
{

    for (; !S1->empty(); S1->pop())
    {
        T current_element {S1->front()};
        std::cout<< current_element<< " ";
        //to prevent losing elements after printing
        S2->push (current_element);

    }

    for (; !S2->empty(); S2->pop())
    {

        S1.push(S2->front());

    }
}


template<typename T>
Queue<T>::~Queue()
{
    delete S1;
    delete S2;

}
//Costly push and non-costly pop
//to be Implemented later.
