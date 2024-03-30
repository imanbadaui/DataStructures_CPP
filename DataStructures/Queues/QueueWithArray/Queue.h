#ifndef QUEUE_H
#define QUEUE_H

#include <exception>
#include <cstdlib>
template <typename T>
class Queue
{
public:
    Queue(const long& max_size = 100);
    bool is_empty ( ) const;
    bool is_full ( ) const;
    long size() const;
    bool inqueue (const T& element );
    bool dequeue ( );
    bool front_queue(T& element ) const;
    bool clear( );
    bool traverse(void (*func) (T& element) )const;
    Queue( const Queue& otherQueue);
    const Queue& operator=( const Queue& otherQueue);
    virtual ~Queue();

protected:
    long front;
    long rear;
    long counter;
    long max_s;
    T *entry;
private:
    void copy_elements ( const Queue& otherQueue);
    void alloc_array();
};


template <typename T>
Queue<T>::Queue(const long& max_size): counter{0}, front{0}
{
    if (max_size <= 0)
        max_s = 100;

    max_s = max_size;
    rear = max_s - 1;
    alloc_array();

}

template <typename T>
void Queue<T>::alloc_array()
{
    try
    {
        entry = new T[max_s];
    }
    catch(std::exception &ex)
    {
        delete[] entry;
        entry = nullptr;
        exit(EXIT_FAILURE);
    }

}

template <typename T>
bool Queue<T>::is_empty ( ) const
{
    return !counter;
}

template <typename T>
bool Queue<T>::is_full ( ) const
{
    return (counter == max_s);
}

template <typename T>
long Queue<T>::size() const
{
    return counter;
}


template <typename T>
bool Queue<T>::inqueue (const T& element )
{
    if (is_full())
    {
        return 0;

    }
    else
    {
        rear = (rear+1) % max_s;
        entry[rear] = element;
        ++counter;
        return 1;
    }

}

template <typename T>
bool Queue<T>::dequeue ( )
{

    if(is_empty())
    {
        return 0;
    }
    else
    {
        front = (front+1) % max_s;
        --counter;
        return 1;
    }

}

template <typename T>
bool Queue<T>::front_queue(T& element ) const
{

    if(is_empty())
    {

        return 0;
    }
    else
    {
        element  = entry[front];
        return 1;
    }

}
template <typename T>
bool Queue<T>::clear( )
{
    if(is_empty())
    {

        return 0;
    }
    else
    {
        front = 0;
        rear = max_s -1;
        counter = 0;
        return 1;
    }

}

template <typename T>
bool Queue<T>::traverse(void (*func) (T& element) )const
{

    if(is_empty())
    {

        return 0;
    }
    else
    {

        for (int i {front}, index {0} ; index < counter; ++index)
        {
            func(entry[i]);
            i = (i+1) % max_s;

        }
        return 1;
    }

}
template <typename T>
void Queue<T>::copy_elements ( const Queue& otherQueue)
{
    if(!is_empty())
    {
        clear();
        delete [] entry;
        entry = nullptr;

    }
    front = otherQueue.front;
    rear = otherQueue.rear;
    counter = otherQueue.counter;
    max_s = otherQueue.max_s;
    alloc_array();

    //if other queue is empty: won't enter this loop
    for (int i {front},index {0} ; index < counter; ++index)
    {

        entry [i] = otherQueue.entry[i];
        i = (i+1) % max_s;

    }

}

template <typename T>
Queue<T>::Queue( const Queue<T>& otherQueue)
{
    //counter = 0: to avoid checking for empty queue in copy_elements func
    counter = 0;
    copy_elements(otherQueue);

}
template <typename T>
const Queue<T>& Queue<T>::operator=( const Queue<T>& otherQueue)
{
    copy_elements(otherQueue);
}


template <typename T>
Queue<T>::~Queue()
{
    delete [] entry;
}


#endif // QUEUE_H
