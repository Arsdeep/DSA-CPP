#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
    private:
    Node* head;

    public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtBeginning(int value)
    {
        Node* tmp = new Node(value);
        tmp->next = head;
        head = tmp;
    }

    void insertAtEnd(int value)
    {
        Node* tmp = new Node(value);

        if (head == nullptr)
            head = tmp;
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = tmp;
        }
    }

    void insertAt(int value,int index)
    {
        if(index<0)
            throw std::runtime_error("Insert Index Not in Range!!");

        if(index==0)
            return insertAtBeginning(value);
        
        Node *tmp = head;
        
        while(--index)
        {
            if(tmp->next == nullptr)
                throw std::runtime_error("Insert Index Not in Range!!");
            tmp = tmp->next;
        }

        Node *n = new Node(value);

        n->next = tmp->next;
        tmp->next = n;
    }

    int deleteAtBeginning()
    {
        if(head == nullptr)
            throw std::runtime_error("No Element Left To Delete!!");
        Node *tmp = head;
        int dat = head->data;
        head = head->next;
        delete tmp;
        return dat;
    }

    int deleteAtEnd()
    {
        if (head == nullptr)
            throw std::runtime_error("No Element Left To Delete!!");

        Node* tmp = head;
        if (tmp->next == nullptr)
        {
            int dat = head->data;
            delete tmp;
            head = nullptr;
            return dat;
        }

        Node* tmp2 = tmp->next;
        while (tmp2->next != nullptr)
        {
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }

        int dat = tmp2->data;
        delete tmp2;
        tmp->next = nullptr;
        return dat;
    }
    
    int deleteAt(int index)
    {
        if(index<0)
            throw std::runtime_error("Insert Index Not in Range!!");

        if(index==0)
            return deleteAtBeginning();
        
        Node *tmp = head;
        Node *tmp2 = head->next;

        while(--index)
        {
            if(tmp2->next == nullptr)
                throw std::runtime_error("Insert Index Not in Range!!");
            tmp = tmp->next;
            tmp2 = tmp2->next;
        }

        tmp->next = tmp2->next;
        int dat = tmp2->data;
        delete tmp2;
        return dat;
    }

    void show() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList l;

    for(int i = 1 ; i<=5 ; i++)
    l.insertAtBeginning(i);

    l.show();

    return 0;
}
