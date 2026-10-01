#include <iostream>
using namespace std;

class Nodetype
{
public:
    int data;
    Nodetype* next;
    Nodetype* prev;

    Nodetype(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    Nodetype* first;
    Nodetype* last;

    DoublyLinkedList()
    {
        first = NULL;
        last = NULL;
    }

    // Insert before the first node
    void insertFirst(int value)
    {
        Nodetype* p = new Nodetype(value);

        if (first == NULL)
        {
            first = last = p;
            p->next = NULL;
            p->prev = NULL;
        }
        else
        {
            p->next = first;
            p->prev = NULL;
            first->prev = p;
            first = p;
        }
    }

    // Insert after the last node
    void insertLast(int value)
    {
        Nodetype* p = new Nodetype(value);

        if (first == NULL)
        {
            first = last = p;
            p->next = NULL;
            p->prev = NULL;
        }
        else
        {
            p->next = NULL;
            p->prev = last;
            last->next = p;
            last = p;
        }
    }

    // Insert after a node with given key
    void insertAfterKey(int key, int value)
    {
        Nodetype* q = first;

        while (q != NULL && q->data != key)
        {
            q = q->next;
        }

        if (q == NULL)
        {
            cout << "Key not found." << endl;
            return;
        }

        Nodetype* p = new Nodetype(value);

        p->prev = q;
        p->next = q->next;

        if (q->next != NULL)
        {
            q->next->prev = p;
        }

        q->next = p;

        if (last == q)
        {
            last = p;
        }
    }

    // Display forward
    void displayForward()
    {
        Nodetype* p = first;

        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }

    // Display backward
    void displayBackward()
    {
        Nodetype* p = last;

        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->prev;
        }

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    // Insert after last
    list.insertLast(20);
    list.insertLast(30);
    list.insertLast(40);

    cout << "Original List: ";
    list.displayForward();

    // Insert before first
    list.insertFirst(10);

    cout << "After inserting 10 before first: ";
    list.displayForward();

    // Insert after key 30
    list.insertAfterKey(30, 35);

    cout << "After inserting 35 after 30: ";
    list.displayForward();

    cout << "List in backward direction: ";
    list.displayBackward();

    return 0;
}
