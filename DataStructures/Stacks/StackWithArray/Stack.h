#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
    Stack(const int max=100) : top{0}, max_size{max}
    {
        arr = new T[max_size];

    }
    bool is_full() const
    {
        return (top == max_size);
    }

    bool is_empty() const
    {
        return (top == 0);
    }

    void  push (const T& element)
    {
        if(!is_full())
        arr[top++] = element;
    }

    void  pop(T& element)
    {
        if(!is_empty()){
        element = arr[top-1];
        top--;
        }
    }

    void stack_top(T& element) const 
    {
         if(!is_empty())
        element  = arr[top-1];
    }

    int length() const
    {
        return top;
    }

    int size() const
    {
        return max_size;
    }

    void clear()
    {
        top = 0;
    }

    void traverse (void (*func) (const T& stack_element))
    {
        for(int i{top-1}; i >= 0 ; --i )
        {
            func(arr[i]);
        }
    }

    Stack (const Stack<T>& otherStack)
    {
        arr = nullptr;
        top = 0;
        copy_stack(otherStack);
    }

    const Stack<T>& operator= (const Stack<T>& otherStack)
    {
        if(this != &otherStack)
        {
            copy_stack(otherStack);
        }
        return *this;
    }

    virtual ~Stack()
    {
        delete[] arr;

    }

private:
    int top;
    int max_size;
    T *arr;

    void copy_stack(const Stack<T>& otherStack)
    {
        if(!is_empty())
        {
            delete[] arr;
        }

        max_size = otherStack.max_size;
        top = otherStack.top;
        arr = new T [max_size];

        for (int i {0}; i < top ; ++i)
        {
            arr[i] = otherStack.arr[i];
        }
    }
};

#endif // STACK_H
