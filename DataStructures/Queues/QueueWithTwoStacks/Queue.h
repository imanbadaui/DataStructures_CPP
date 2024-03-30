#ifndef QUEUE_H
#define QUEUE_H
#include<stack>
#include<list>
/*
***Implement Queue with two stacks in two ways:
*Costly push and non-costly pop:
*for pushing: move all elements from S1 to S2,
              push new element in S1
              move all elements back from S2 to S1
*for popping: just pop top of S1

*Costly pop and non-costly push:
*for pushing: push elements normally in S1 in stack order
*for popping: move all elements from S1 to S2
              pop top of S2
              move all elements back from S2 to S1


*/
template<typename T>
class Queue
{
public:
    Queue();
    Queue(std::initializer_list<T> l);
    bool empty() const ;
    bool push_front(const T& element);
    bool pop_back();
    bool front(T& element);
    size_t size () const;
    void print_Q();
    virtual ~Queue();

protected:
    std::stack<T,std::list<T>>  *S1;
    std::stack<T,std::list<T>>  *S2;
};

#endif // QUEUE_H
