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

    void remove_spec(int key)
    {
        Nodetype* q;
        Nodetype* q1;

        q1 = NULL;
        q = first;

        while (q != NULL && q->data != key)
        {
            q1 = q;
            q = q->next;
        }

        if (q == NULL)
        {
            cout << "Not found supplied key" << endl;
        }
        else if (q == first && q == last)
        {
            delete q;
            first = last = NULL;
        }
        else if (q == last)
        {
            q1->next = NULL;
            last = q1;

            delete q;
        }
        else
        {
            q1->next = q->next;

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
    int key;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        list.insert_end();
    }

    cout << "\nOriginal Linked List: ";
    list.display();

    cout << "Enter the key you want to delete: ";
    cin >> key;

    list.remove_spec(key);

    cout << "After deleting the node: ";
    list.display();

    return 0;
}
