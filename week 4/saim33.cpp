#include <iostream>
using namespace std;

class Nodetype
{
public:
    int data;
    Nodetype* next;
    Nodetype* prev;

    Nodetype()
    {
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

    void insert_end()
    {
        Nodetype* p;

        p = new Nodetype;

        cout << "Enter the data in node: ";
        cin >> p->data;

        if (first == NULL)
        {
            first = last = p;
        }
        else
        {
            last->next = p;
            p->prev = last;
            last = p;
        }
    }

    void display()
    {
        Nodetype* temp = first;

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
    DoublyLinkedList list;

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        list.insert_end();
    }

    cout << "Doubly Linked List: ";
    list.display();

    return 0;
}
