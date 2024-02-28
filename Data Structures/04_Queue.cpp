#include<iostream>
using namespace std;

class Queue
{
    int *arr;
    int head,tail,size;

public:

    Queue(int n)
    {
        arr = new int[n];
        head = 0;
        tail = 0;
        size = n;
    }

    void enqueue(int n)
    {
        if(tail<size)
        {
            arr[tail++] = n;
        }
        else
            throw std::runtime_error("Queue is Full!!");
    }

    int dequeue()
    {
        if(head < tail)
            return arr[head++];
        else
            throw std::runtime_error("Queue is Empty!!");
    }

    void show()
    {
        for(int i = head ; i<tail ; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"(Total - "<<tail-head<<")"<<endl;
    }
};


int main()
{
    Queue q(10);

    for(int i = 1 ; i<=5 ; i++)
        q.enqueue(i);

    q.show();

    std::cout<<std::endl<<std::endl;

    std::cout<<"DeQueued Element - "<<q.dequeue()<<","<<q.dequeue();

    std::cout<<std::endl<<std::endl;

    q.show();

    return 0;
}