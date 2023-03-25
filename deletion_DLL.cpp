#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory freed for data " << val << endl;
    }
};


// Return length of the linked list     
int getLength(Node* head)
{
    int cnt = 0;
    Node* temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtHead(Node*& head, Node*& tail, int data)
{
    // If DLL is empty
    if (head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node*& head, Node*& tail, int data)
{
    // If DLL is empty
    if (tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }


}

void insertAtPosition(Node*& head, Node*& tail, int position, int data)
{
    // Inserting at start
    if (position == 1)
    {
        insertAtHead(head, tail, data);
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
        insertAtTail(head, tail, data);
        return;
    }

    // creating a node
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}


void deleteNode(Node*& head, Node*& tail, int position)
{
    // Deleting first Node
    if (position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
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

        if (current->next == NULL)
        {
            tail = prev;
        }

        current->prev = NULL;
        prev->next = current->next;
        current->next = NULL;

        delete current;
    }
}

// Prints all the values of linked list
void display(Node* head) {
    Node* temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 4);
    display(head);

    insertAtHead(head, tail, 8);
    display(head);

    insertAtHead(head, tail, 9);
    display(head);

    insertAtTail(head, tail, 5);
    display(head);

    insertAtTail(head, tail, 10);
    display(head);

    insertAtPosition(head, tail, 3, 7);
    display(head);

    insertAtPosition(head, tail, 7, 15);
    display(head);

    insertAtPosition(head, tail, 1, 20);
    display(head);

    deleteNode(head, tail, 1);
    display(head);

    deleteNode(head, tail, 5);
    display(head);

    deleteNode(head, tail, 6);
    display(head);

    insertAtTail(head, tail, 20);
    display(head);
    return 0;
}