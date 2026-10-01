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

    // Insert at end
    void insertEnd(int value)
    {
        Nodetype* p = new Nodetype(value);

        if (first == NULL)
        {
            first = last = p;
        }
        else
        {
            p->prev = last;
            last->next = p;
            last = p;
        }
    }

    // Delete first node
    void deleteFirst()
    {
        if (first == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Nodetype* p = first;

        first = first->next;

        delete p;

        if (first == NULL)
        {
            last = NULL;
        }
        else
        {
            first->prev = NULL;
        }
    }

    // Delete last node
    void deleteLast()
    {
        if (last == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Nodetype* p = last;

        last = last->prev;

        if (last == NULL)
        {
            first = NULL;
        }
        else
        {
            last->next = NULL;
        }

        delete p;
    }

    // Delete node by key
    void deleteByKey(int key)
    {
        Nodetype* p = first;

        while (p != NULL && p->data != key)
        {
            p = p->next;
        }

        if (p == NULL)
        {
            cout << "Key not found." << endl;
            return;
        }

        // List has only one node
        if (first == p && last == p)
        {
            first = NULL;
            last = NULL;

            delete p;
        }

        // Delete first node
        else if (p == first)
        {
            first = first->next;
            first->prev = NULL;

            delete p;
        }

        // Delete last node
        else if (p == last)
        {
            last = last->prev;
            last->next = NULL;

            delete p;
        }

        // Delete inner node
        else
        {
            p->next->prev = p->prev;
            p->prev->next = p->next;

            delete p;
        }
    }

    // Display list
    void display()
    {
        Nodetype* p = first;

        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.insertEnd(50);

    cout << "Original List: ";
    list.display();

    list.deleteFirst();

    cout << "After deleting first node: ";
    list.display();

    list.deleteLast();

    cout << "After deleting last node: ";
    list.display();

    list.deleteByKey(30);

    cout << "After deleting node with key 30: ";
    list.display();

    return 0;
}
