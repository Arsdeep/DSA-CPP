#include<iostream>
using namespace std;

class Node
{
    int data;
    Node * next;

public:

    friend class Queue;

    Node(int n)
    {
        data = n;
        next = nullptr;
    }
};

class Queue
{
    Node * head;
    Node * tail;

public:

    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(int n)
    {
        Node *tmp = new Node(n);
        if(head == nullptr && tail == nullptr)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }

    int dequeue()
    {
        if(head == nullptr && tail == nullptr)
            throw std::runtime_error("No Element Left To Delete!!");
        
        int n = head->data;

        if(head == tail)
        {
            delete head;

            head = nullptr;
            tail = nullptr;

            return n;
        }
        
        Node *tmp = head;
        head = head->next;
        delete tmp;

        return n;
    }

    void show()
    {
        Node* tmp = head;
        while (tmp != nullptr)
        {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

};


int main()
{
    Queue q;

    for(int i = 1  ; i <= 10 ; i++)
    {
        q.enqueue(i);
    }

    q.show();

    cout<<"\nDequeued Element - "<<q.dequeue()<<","<<q.dequeue()<<"\n\n";

    q.show();

    return 0;
}
