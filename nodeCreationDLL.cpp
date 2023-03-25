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
    Node* node1 = new Node(1);
    Node* head = node1;

    display(head);

    return 0;
}