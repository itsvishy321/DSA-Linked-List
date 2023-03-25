#include <bits/stdc++.h>
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

void insertAtTail(Node*& head, Node*& tail, int data)
{
    // If SLL is empty
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

void createLL(Node*& head, Node*& tail, vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        insertAtTail(head, tail, A[i]);
    }
}

void display(Node* head)
{
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl << endl;
}

int main()
{
    vector<int> A = { 1,2,2,3,3,3,4,4,5,5 };
    Node* head = NULL;
    Node* tail = NULL;
    createLL(head, tail, A);
    display(head);
    return 0;
}