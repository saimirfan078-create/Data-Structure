#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* head = NULL;

    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num % 2 != 0)  
    {
        Node* newnode1 = new Node;
        newnode1->data = num;
        newnode1->next = NULL;

        head = newnode1;

        Node* newnode2 = new Node;
        newnode2->data = num;
        newnode2->next = NULL;

        newnode1->next = newnode2;
    }
    else  
    {
        Node* newnode = new Node;
        newnode->data = num;
        newnode->next = NULL;

        head = newnode;
    }
    Node* ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    return 0;
}
