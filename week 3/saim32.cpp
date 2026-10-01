#include <iostream>
using namespace std;

class Nodetype
{
public:
    int data;
    Nodetype* next;

    Nodetype()
    {
        next = NULL;
    }
};

class LinkedList
{
public:
    Nodetype* first;
    Nodetype* last;

    LinkedList()
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
            last = p;
        }
    }

    Nodetype* search(int key)
    {
        Nodetype* p = NULL;

        p = first;

        while (p != NULL && p->data != key)
        {
            p = p->next;
        }

        return p;
    }

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
    LinkedList list;

    int n;
    int key;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        list.insert_end();
    }

    cout << "Linked List: ";
    list.display();

    cout << "Enter value to search: ";
    cin >> key;

    Nodetype* result = list.search(key);

    if (result == NULL)
    {
        cout << "Value not found." << endl;
    }
    else
    {
        cout << "Value found: " << result->data << endl;
    }

    return 0;
}
