#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include "ListNode.h"
template <typename T>
class List
{
public:
    List();
    List(std::initializer_list<T> inList);
    bool isEmpty()const;
    bool isFull()const;
    int listSize()const;
    //const item to deep copy item inside list.
    void insertList(int pos, const T &item);
    //item to retrieve deleted item.
    //if item deleted return 1 else return 0.
    int deleteList(int pos, T &item);
    //if pos is in the list return 1 else return 0.
    int retrieveItem (int pos, T &item);
    //replace position 0 by item.
    // return 1 if pos is in the list else return 0.
    int replaceItem (int pos, const T &item) ;
    //return 1 if list is not empty and 0 if empty.
    int destroyList ();
    //return 1 if list is not empty and 0 if empty.
    int traverseList(void (*visit) (const T &item, const int &pos));
    //return true and pos if item in the list, return false if not.
    bool sequentialSearch(const T &target, int &pos);
    ~List();

protected:
    ListNode<T> *current;
    int currentPos;
    int size;
};

#endif // LIST_H
