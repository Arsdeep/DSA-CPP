#include<iostream>
using namespace std;

class Stack
{
protected:

    int *val;
    int top,size;

public:

    Stack(int n)
    {
        val = new int[n];
        top = 0;
        size = n;
    }

    //Pushes an Element in the Stack, if Stack is Full returns 0. If Push is successful returns 1
    int push(int element)
    {
        if(top >= size)
            return 0;

        val[top] = element;
        top++;

        return 1;
    }

    //Pops an Element from the Stack and returns it, raises an error if No element Present
    int pop()
    {
        if(top == 0)
            throw runtime_error("Stack is Empty!!");

        return val[--top];
    }

    //Returns the TopMost Element of the Stack
    int peek()
    {
        if(top == 0)
            throw runtime_error("Stack is Empty!!");

        return val[top];
    }

    //Displays all the elements of the Stack
    void show()
    {
        for(int i = 0; i<top ; i++)
            std::cout<<val[i]<<" ";
        std::cout<<"(Total - "<<top<<")"<<endl;
    }

    ~Stack()
    {
        delete[] val;
    }
};

int main(int argc, char const *argv[])
{
    Stack a(10);

    for(int i = 1 ; i<15 ; i++)
        cout<<"Pushed Element "<<i<<(a.push(i)?" Successfully":" Unsucesfully")<<endl;

    cout<<"\n\nPopped Elements - "<<a.pop()<<","<<a.pop()<<"\n\n";

    a.show();
    
    return 0;
}