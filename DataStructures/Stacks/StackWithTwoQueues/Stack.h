#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <queue>
#include <list>
/**
* this stack is made up of two queues with two algorithm:

* costly pushing and non-costly popping:
*for pushing: move elements from Q1 to Q2
						 push new element in Q1,
             move all elements back from Q2 to Q1
* for popping: just pop front of Q1

* costly popping and non-costly pushing:
*for pushing: push elements in Q1 in normal Queue order
*for popping: move all elements from Q1 to Q2 except last element of Q1
							pop it from Q1
							move all elements back from Q2 to Q1

*/

template <typename T>
class Stack
{
public:
    Stack();
    Stack(std::initializer_list<T> l);
    bool empty() const ;
    bool push_top(const T& element);
    bool pop_top();
    bool top(T& element);
    size_t size () const;
    void print_stack();
    virtual ~Stack();

protected:
    std::queue<T,std::list<T>>  *Q1;
    std::queue<T,std::list<T>>  *Q2;

};
#endif // STACK_H
