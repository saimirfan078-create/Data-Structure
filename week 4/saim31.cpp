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

    void swapNodes(int value1, int value2)
    {
        if (value1 == value2)
        {
            return;
        }

        Node* prev1 = NULL;
        Node* curr1 = head;

        while (curr1 != NULL && curr1->data != value1)
        {
            prev1 = curr1;
            curr1 = curr1->next;
        }

        Node* prev2 = NULL;
        Node* curr2 = head;

        while (curr2 != NULL && curr2->data != value2)
        {
            prev2 = curr2;
            curr2 = curr2->next;
        }

        if (curr1 == NULL || curr2 == NULL)
        {
            cout << "Both values are not found in the list." << endl;
            return;
        }

        if (prev1 != NULL)
        {
            prev1->next = curr2;
        }
        else
        {
            head = curr2;
        }

        if (prev2 != NULL)
        {
            prev2->next = curr1;
        }
        else
        {
            head = curr1;
        }

        Node* temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
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

    cout << "Original List: ";
    list.display();

    int value1, value2;

    cout << "Enter first value: ";
    cin >> value1;

    cout << "Enter second value: ";
    cin >> value2;

    list.swapNodes(value1, value2);

    cout << "List after swapping nodes: ";
    list.display();

    return 0;
}
