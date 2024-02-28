#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = nullptr;
    }

    //Pushes an Element in the Stack
    void push(int data)
    {
        Node* tmp = new Node(data);
        tmp->next = top;
        top = tmp;
    }

    //Pops an Element from the Stack and returns it, raises an error if No element Present
    int pop()
    {
        if(top->next == nullptr)
            throw std::runtime_error("Stack is Empty!!");

        Node *tmp = top;
        int dat = top->data;
        top = top->next;
        delete tmp;
        return dat;
    }

    // Get the top element of the stack
    int peek()
    {
        if(top->next == nullptr)
            throw std::runtime_error("Stack is Empty!!");

        return top->data;
    }

    void show()
    {
        Node *tmp = top;
        int i=0;
        while(tmp != nullptr)
        {
            i++;
            std::cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        std::cout<<"(Total - "<<i<<")"<<endl;
    }

};

int main(int argc, char const *argv[])
{
    Stack a;

    for(int i = 1 ; i<=5 ; i++)
    {
        a.push(i);
        cout<<"Pushed Element "<<i<<endl;
    }
    

    cout<<"\n\nPopped Elements - "<<a.pop()<<","<<a.pop()<<"\n\n";

    a.show();
    
    return 0;
}
