#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode
{
public:
    ListNode(T data) :data{data}, next{nullptr}, back{nullptr}
    {
    }

    T data;
    ListNode<T> *next;
    ListNode<T> *back;

};

#endif // LISTNODE_H
