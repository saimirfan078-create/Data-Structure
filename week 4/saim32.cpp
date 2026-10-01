#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class DoublyNode
{
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;

    DoublyNode(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    void insert(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    DoublyNode* convertToDoubly()
    {
        if (head == NULL)
        {
            return NULL;
        }

        DoublyNode* doublyHead = NULL;
        DoublyNode* doublyTail = NULL;

        Node* temp = head;

        while (temp != NULL)
        {
            DoublyNode* newNode = new DoublyNode(temp->data);

            if (doublyHead == NULL)
            {
                doublyHead = newNode;
                doublyTail = newNode;
            }
            else
            {
                doublyTail->next = newNode;
                newNode->prev = doublyTail;
                doublyTail = newNode;
            }

            temp = temp->next;
        }

        return doublyHead;
    }

    void displayDoubly(DoublyNode* head)
    {
        DoublyNode* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Singly Linked List: ";
    list.display();

    DoublyNode* doublyHead = list.convertToDoubly();

    cout << "Doubly Linked List: ";
    list.displayDoubly(doublyHead);

    return 0;
}
