#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;

        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for " << val << endl;
    }
};

// Inserting on the basis of the value passed 
// if value found : insert after it
// else : Do not insert

void insertNode(Node*& tail, int value, int data)
{
    // empty list
    if (tail == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list
        Node* current = tail;
        while (current->data != value)
        {
            current = current->next;
        }

        Node* temp = new Node(data);
        temp->next = current->next;
        current->next = temp;
    }
}


// Delete function for circular linked list
void deleteNode(Node*& tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    else
    {
        Node* prev = tail;
        Node* current = prev->next;



        while (current->data != value)
        {
            prev = current;
            current = current->next;
        }

        if (current == prev)
            tail = NULL;

        else if (current == tail)
            tail = prev;

        prev->next = current->next;
        current->next = NULL;

        delete current;
    }
}

// circular linked list traversal
void display(Node*& tail)
{

    if (tail == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = tail;

    do
    {
        cout << temp->data << "  ";
        temp = temp->next;
    } while (temp != tail);


    cout << endl;
}

int main()
{
    Node* tail = NULL;

    insertNode(tail, 5, 7);
    display(tail);

    insertNode(tail, 7, 3);
    display(tail);

    insertNode(tail, 3, 4);
    display(tail);

    insertNode(tail, 7, 8);
    display(tail);

    deleteNode(tail, 7);
    display(tail);


    return 0;
}