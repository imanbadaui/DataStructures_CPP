#include <initializer_list>
#include "List.h"
#include "ListNode.h"

template <typename T>
List<T>::List():current{nullptr}, currentPos{0}, size{0}
{
}

template <typename T>
List<T>::List(std::initializer_list<T> inList):current{nullptr}, currentPos{0}, size{0}
{
    for (auto i {rbegin(inList)}; i!= rend(inList); ++i)
    {
        T item = *i;
        int pos = currentPos;
        insertList(currentPos, item);
        ++pos;
    }

}

template <typename T>
bool List<T>::isEmpty()const
{
    return (!size);
}

template <typename T>
bool List<T>::isFull()const
{
    return 0;
}

template <typename T>
int List<T>::listSize()const
{
    return size;
}

//insertion from position 0 to position size
template <typename T>
void List<T>::insertList(int pos, const T &item)
{

    ListNode<T> *temp = new ListNode<T>(item);
    temp->next = temp->back = temp;

    if(pos > size)
        pos = size;
    if(size != 0){
		    if (pos <= currentPos)
		    {
		        for (; currentPos > pos ; --currentPos)
		            current= current->back;
		    } else
		    {
		        for (; currentPos < pos; ++currentPos)
		            current = current->next;
		    }
		        temp->next = current;
		        temp->back = current->back;
		        current->back->next = temp;
		        current->back = temp;
	}
    current = temp;
    ++size;
}

//deletion from position 0 to position size-1
template <typename T>
int List<T>::deleteList(int pos, T &item)
{
    //list is empty.
    //deletion from non-exist position
    if(size == 0 || pos > size-1)
    {
        return 0;
    }
    else
    {
        ListNode<T> *temp;
        if(pos > currentPos)
        {
            for (; currentPos < pos ; ++currentPos)
                current = current->next;
        }
        else if(pos < currentPos)
        {
            for(; currentPos > pos; --currentPos)
                current = current-> back;
        }

        temp = current;
        item = temp->data;
        //only one element in the list
        if(size == 1)
        {
            delete temp;
            current = nullptr;
						currentPos= 0;
        }
        else
        {
            //for deleting first or last or middle elements.
            current->back->next = current->next;
            current->next->back = current ->back;
            current = current->next;
            delete temp;
            //for deleting last element. circular imp still the same.
            if (pos == size-1)
                currentPos= 0;
        }
        --size;
    }
    return 1;
}

//Retrieve from position 0 to position size-1
template <typename T>
int List<T>::retrieveItem (int pos, T &item)
{
    if(size == 0 || pos > size-1)
    {
        return 0;
    }
    else
    {
        if (pos > currentPos)
        {
            for(; currentPos< pos; ++currentPos)
                current =current -> next;
        }
        else
        {
            for(; currentPos > pos; --currentPos)
                current = current-> back;
        }
        item = current->data;
    }
    return 1;
}

//Replace from position 0 to position size-1
template <typename T>
int List<T>::replaceItem (int pos, const T &item)
{
    if(size == 0 || pos > size-1)
    {
        return 0;
    }
    else
    {
        if (pos > currentPos)
        {
            for(; currentPos< pos; ++currentPos)
                current =current -> next;
        }
        else
        {
            for(; currentPos > pos; --currentPos)
                current = current-> back;
        }
        current->data = item ;
    }
    return 1;
}
//Delete from current Position 0 until size is 0.
template <typename T>
int List<T>::destroyList ()
{

    if(size == 0)
    {
        return 0;
    }
    else
    {
        ListNode<T> *temp;
        while (currentPos < size )
        {
            temp = current;

            if (size == 1)
            {
                current = nullptr;
                currentPos = 0;
            }
            else
            {
                current -> next -> back = current ->back;
                current -> back -> next = current -> next;
                current = current -> next;
                if (currentPos == size -1)
                    currentPos = 0;
            }

            delete temp;
            --size;
        }
        return 1;
    }
}

//Traverse from current Position to current position.
template <typename T>
int List<T>::traverseList(void (*visit) (const T &item, const int &pos))
{
    if (size == 0)
    {
        return 0;
    }
    else
    {
        for (int i{0}; i < size ; ++i)
        {
            visit  (current->data, currentPos);
            current = current->next;
            ++currentPos;
            if (currentPos == size)
                currentPos = 0;
        }
        return 1;
    }
}

template <typename T>
List<T>::~List()
{
    destroyList();

}

template <typename T>
bool List<T>::sequentialSearch(const T &target, int &pos)
{
    int sizeForSearch{size};
    if (size == 0)
    {
        return false;
    }
    else
    {
        while (sizeForSearch)
        {
            current = current -> next;
            ++currentPos;
            if(currentPos == size)
                currentPos = 0;

            if(current-> data == target)
            {
                pos = currentPos;
                return true;
            }
            --sizeForSearch;
        }
        return false;
    }
}
