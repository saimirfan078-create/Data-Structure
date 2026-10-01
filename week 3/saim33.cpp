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

    void insert_after(int key)
    {
        Nodetype* p = NULL;

        p = search(key);

        if (p == NULL)
        {
            cout << "Value not found" << endl;
        }
        else
        {
            Nodetype* Newnode;

            Newnode = new Nodetype;

            cout << "Enter the data for new node: ";
            cin >> Newnode->data;

            if (p == last)
            {
                p->next = Newnode;
                last = Newnode;
            }
            else
            {
                Newnode->next = p->next;
                p->next = Newnode;
            }

            cout << "New node linked successfully" << endl;
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

    cout << "Original Linked List: ";
    list.display();

    cout << "Enter the key after which you want to insert: ";
    cin >> key;

    list.insert_after(key);

    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
