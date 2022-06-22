//myQueue.h

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename Object>
// using namespace std;

class myQueue
{
private:
    Object *queue;
    int q_size;
    int q_capacity;
    int q_front;
    int q_back;

public:
    myQueue()
    {
        q_size = 0;
        q_capacity = 0;
        q_front = 0;
        q_back = 0;
        // queue = new Object[500];
    }

    myQueue(const int& size)
    {
        q_capacity = size;
        q_size = 0;
        q_front = 0;
        q_back = 0;
        queue =  new Object[q_capacity];
    }

    //copy constructor
    myQueue(const myQueue<Object> & rhs)
    {
        q_size = rhs.q_size;
        q_capacity = rhs.q_capacity;
        q_front = rhs.q_front;
        q_back = rhs.q_back;
        queue = new Object[q_capacity];

        for(int i = 0; i < rhs.q_size; ++i)
        {
            this->queue[i] = rhs.queue[i];
        }
    }

    //move constructor
    myQueue(myQueue<Object> && rhs)
    {
        q_size = rhs.q_size;
        q_capacity = rhs.q_capacity;
        queue = rhs.queue;
        q_front = rhs.q_front;
        q_back = rhs.q_back;

        rhs.q_size = 0;
        rhs.q_capacity = 0;
        rhs.q_front = 0;
        rhs.q_back = 0;
        rhs.queue = nullptr;
    }

    //copy assignment operator
    myQueue& operator= ( const myQueue & rhs)
    {
        myQueue queue2(rhs);
        std::swap(*this, queue2);

        return *this;
    }

    //copy assignment operator -> input params temporary
    myQueue& operator= (myQueue && rhs)
    {
        std::swap(q_size, rhs.q_size);
        std::swap(q_capacity, rhs.capacity);
        std::swap(queue, rhs.queue);
        std::swap(q_front, rhs.q_front);
        std::swap(q_back, rhs.q_back);

        return *this;
    }

    ~myQueue(void)
    {
        delete[] queue;
        queue = nullptr;
    }

    void reserve(const int & capacity)
    {
        if (q_size == q_capacity)
        {
            q_capacity = capacity * 2;
            Object *temp = new Object[q_capacity];

            int f = q_front;
            int i = 0;

            while (i != q_size)
            {
                temp[i] = queue[f];
                i++;
                f++;
                if(f == q_size)
                {
                    f = 0;
                }
            }
            swap(queue, temp);
            delete[] temp;
            q_front = 0;
            q_back = q_size - 1;
        }
    }

    void enqueue(const Object & rhs)
    {
        if (q_size == q_capacity)
        {
            reserve(q_capacity * 2);
        }
        q_back = (q_back + 1) % q_capacity;
        queue[q_back] = rhs;
        q_size++;
    }

    void dequeue(void)
    {
        if (empty())
        {
            throw std::runtime_error("EEROR: Cannot dequeue with an empty list.\n");
        }
        q_front = (q_front + 1) % q_capacity;
        // queue[q_front] = rhs;
        q_size--;
    }

    Object & front(void)
    {
        if (empty())
        {
            throw std::runtime_error("ERROR: Cannot find front for empty queue.\n");
        }
        return queue[q_size - 1];
    }

    int size(void)
    {
        return (q_size);
    }

    bool empty(void)
    {
        return(q_size <= 0);
    }

};