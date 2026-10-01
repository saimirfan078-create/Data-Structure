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

    void delete_all()
    {
        Nodetype* p;

        while (first != NULL)
        {
            p = first;

            first = first->next;

            delete(p);
        }

        last = NULL;
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
        list.insert_end();
    }

    cout << "\nOriginal Linked List: ";
    list.display();

    list.delete_all();

    cout << "After deleting all nodes: ";
    list.display();

    return 0;
}
