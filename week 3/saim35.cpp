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

    void delete_last()
    {
        Nodetype* q;
        Nodetype* q1;

        if (first == NULL)
        {
            cout << "\nLinked List is empty" << endl;
        }
        else
        {
            q = last;
            q1 = first;

            if (first == last)
            {
                first = last = NULL;
            }
            else
            {
                while (q1->next != last)
                {
                    q1 = q1->next;
                }

                q1->next = NULL;
                last = q1;
            }

            delete q;
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
        list.insert_end();
    }

    cout << "\nOriginal Linked List: ";
    list.display();

    list.delete_last();

    cout << "After deleting last node: ";
    list.display();

    return 0;
}
