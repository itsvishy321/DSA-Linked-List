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
    return 0;
}