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
};

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
        // Create new node
        Node* temp = new Node(data);
        temp->next = head;
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
    temp->next = nodeToInsert;
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
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 10);
    display(head);

    insertAtHead(head, tail, 69);
    display(head);

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    display(head);

    // insertAtHead(head, 22);
    insertAtPosition(head, tail, 5, 22);
    display(head);

    insertAtTail(head, tail, 30);
    display(head);

    return 0;
}