//myStack.h

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename Object>
// using namespace std;

class myStack
{
private:
    Object *stack;
    int s_size;
    int s_capacity;
    int s_index;

public:
    myStack(){}

    //constructor
    myStack(const int& size)
    {
        s_size = 0;
        s_capacity = size;
        stack =  new Object[s_capacity];
    }

    //copy constructor
    myStack(const myStack<Object> & rhs)
    {
        s_size = 0;
        s_capacity =10;
        stack =  new Object[s_capacity];
        for (int i = 0; i < rhs.s_size; i++)
        {
            push(rhs.stack[i]);
        }
    }

    //copy assignment operator
    myStack& operator= ( const myStack & rhs)
    {
        myStack copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    //move constructor
    myStack(myStack<Object> && rhs)
    {
        s_size = rhs.s_size;
        s_capacity = rhs.s_capacity;
        stack = rhs.stack;

        rhs.s_size = 0;
        rhs.stack = nullptr;
    }

    //copy assignment operator
    myStack& operator= (myStack && rhs)
    {
        std::swap(s_size, rhs.s_size);
        std::swap(stack, rhs.stack);
        
        return *this;
    }

    //destructor
    ~myStack(void)
    {
        delete[] stack;
        stack = nullptr;
    }

    // //allocate memory block with capacity - built in push method
    // void reserve(const int & capacity) {}

    //push element to stack
    void push(const Object & rhs)
    {
        //resize stack if needed
        if(s_size == s_capacity)
        {
            s_capacity = s_capacity * 2;
            Object *temp  = new Object[s_capacity];
            
            for (int i = 0 ; i < s_size; i++)
                {
                    temp[i] = stack[i];
                }
            std::swap(stack, temp);
            delete [] temp;
        }

        stack[s_size] = rhs;
        s_size++;
    }

    //remove element from stack
    void pop(void)
    {
        if(empty())
        {
            throw std::runtime_error("ERROR: stack is empty, cannot pop.");
        }
        else
        {
            Object temp = stack[s_size - 1];
            s_size--;
        }
    }

    //return top of stack
    Object & top(void)
    {
        return stack[s_size - 1];
    }

    //return size
    int size(void)
    {
        return s_size;
    }

    //returns whether stack is empty
    bool empty()
    {
        return(s_size <= 0);
    }

};


