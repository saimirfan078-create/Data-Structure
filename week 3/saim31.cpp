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

    void insert_start()
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
            p->next = first;
            first = p;
        }
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

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        list.insert_start();
    }

    cout << "Linked List: ";
    list.display();

    return 0;
}
