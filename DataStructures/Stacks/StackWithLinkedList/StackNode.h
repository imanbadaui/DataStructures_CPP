#ifndef STACKNODE_H
#define STACKNODE_H

//forward declaration because the compiler does not know there is a class template called Stack yet
template <typename T>
class Stack;

template <typename T>
class StackNode
{
    friend class Stack<T>;

public:
    StackNode() :next{nullptr},back{nullptr}
    {

    }


protected:
    StackNode<T> *next;
    StackNode<T> *back;
    T data;
};

#endif // STACKNODE_H
