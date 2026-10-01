#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
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
            newNode->prev = temp;
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

    void reverseList()
    {
        Node* current = head;
        Node* temp = NULL;

        while (current != NULL)
        {
            temp = current->prev;

            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        if (temp != NULL)
        {
            head = temp->prev;
        }
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

    list.reverseList();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
