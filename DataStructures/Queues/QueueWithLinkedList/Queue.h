#ifndef QUEUE_H
#define QUEUE_H

#include "QueueNode.h"

template <typename T>
class Queue
{
public:
    Queue();
    Queue(const std::initializer_list<T>& l);
    bool is_empty ( ) const;
    bool is_full ( ) const;
    const long& size() const;
    bool inqueue (const T& element );
    bool dequeue ( );
    bool front_queue(T& element ) const;
    bool clear( );
    bool traverse(void (*func) (const T& element) )const;
    Queue( const Queue& otherQueue);
    const Queue& operator=( const Queue& otherQueue);
    virtual ~Queue();

protected:
    QueueNode<T>* front;
    QueueNode<T>* rear;
    long counter;

private:
    void copy_elements ( const Queue& otherQueue);
};
template <typename T>
Queue<T>::Queue():front{nullptr},rear{nullptr}, counter{0}
{
}

template <typename T>
Queue<T>::Queue(const std::initializer_list<T>& l): Queue()
{

    //inQueue elements from initializer list into the Queue with FIFO behavior.
    for(auto i = l.begin(); i != l.end() ; i++)
        inqueue(*i);
}


template <typename T>
bool Queue<T>::is_empty ( ) const
{
    return !counter;
}

template <typename T>
bool Queue<T>::is_full ( ) const
{
    return false;
}
template <typename T>
const long& Queue<T>::size() const
{
    return counter;

}

template <typename T>
bool Queue<T>::inqueue (const T& element)
{
    QueueNode<T> *new_node{new QueueNode<T>{element}};
    //checking for first Node
    if(rear==nullptr)
    {
        front = rear= new_node;
    }
    else
    {
        rear->next= new_node;
        rear = new_node;

    }
    ++counter;
    return true;
}

template <typename T>
bool Queue<T>::dequeue ( )
{
    if (front == nullptr)
    {
        return false;
    }
    else
    {
        QueueNode<T> *temp{front};
        front = front -> next;
        if(front == nullptr) rear = nullptr;
        delete temp;
        --counter;
    }
}

template <typename T>
bool Queue<T>::front_queue(T& element) const
{
    if (front == nullptr)
    {
        return false;
    }
    else
    {
        element = front -> data;
        return true;
    }
}
template <typename T>
bool Queue<T>::clear( )
{
    QueueNode<T> *temp{front};
    if(temp == nullptr)
    {
        return false;
    }
    else
    {
        while(temp != nullptr)
        {

            front= front->next;
            delete temp;
            temp = front;
        }
        rear = nullptr;
        counter = 0;
        return true;
    }
}

template <typename T>
bool Queue<T>::traverse(void (*func) (const T& element) )const
{

    if(front == nullptr)
    {
        return false;
    }
    else
    {
        QueueNode<T> *temp{front};
        while (temp!= nullptr)
        {
            func(temp -> data);
            temp = temp-> next;
        }
        return true;
    }

}

template <typename T>
void Queue<T>::copy_elements ( const Queue& otherQueue)
{
    if(!is_empty()) clear();

    if(otherQueue.is_empty())
    {
        front = rear= nullptr;
        counter = 0;

    }
    else
    {

        QueueNode <T> *new_node;
        QueueNode <T> *temp{otherQueue.front};
        //move first element first
        new_node = new QueueNode<T>(temp -> data);
        front = rear = new_node;
        ++counter;
        temp = temp-> next;

        //move rest elements
        while (temp != nullptr)
        {
            new_node = new QueueNode<T>(temp -> data);
            rear->next = new_node;
            rear = new_node;
            counter++;

        }
    }
}
    template <typename T>
    Queue<T>::Queue( const Queue& otherQueue)
    {
        front = rear= nullptr;
        counter = 0;
        copy_elements(otherQueue);
    }

    template <typename T>
    const Queue<T>& Queue<T>::operator=( const Queue<T>& otherQueue)
    {
        copy_elements(otherQueue);
    }

#endif // QUEUE_H
