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
        int value = this->data;

        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for Node with value " << value << endl;
    }
};

void insertAtHead(Node*& head, int data)
{
    // Create new node
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*& tail, int data)
{
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node*& head, Node*& tail, int position, int data)
{
    // Inserting at start
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Inserting at last
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // creating a node
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}


void deleteNode(Node*& head, Node*& tail, int position)
{
    // Deleting first Node
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;

        // Free the memory
        temp->next = NULL;
        delete temp;

    }

    // Deleting any Node in middle or last Node
    else
    {
        Node* current = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = current;
            current = current->next;
            cnt++;
        }

        // Changing tail if deleting tail
        if (current->next == NULL)
        {
            tail = prev;
        }

        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

void display(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* node1 = new Node(5);

    Node* head = node1;
    insertAtHead(head, 10);
    display(head);

    insertAtHead(head, 69);
    display(head);

    Node* tail = node1;
    insertAtTail(tail, 10);
    insertAtTail(tail, 20);
    display(head);

    // insertAtHead(head, 22);
    insertAtPosition(head, tail, 6, 22);
    display(head);

    insertAtTail(tail, 30);
    display(head);

    deleteNode(head, tail, 2);
    display(head);

    deleteNode(head, tail, 1);
    display(head);

    deleteNode(head, tail, 5);
    display(head);

    insertAtTail(tail, 4);
    display(head);


    return 0;
}