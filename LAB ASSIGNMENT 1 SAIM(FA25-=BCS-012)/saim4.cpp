#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* first;

    LinkedList() {
        first = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (first == NULL) {
            first = newNode;
            return;
        }

        Node* temp = first;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    bool detectLoop() {
        Node* slow = first;
        Node* fast = first;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }

    void createLoop() {
        if (first == NULL)
            return;

        Node* temp = first;
        Node* second = first;

        if (second->next != NULL)
            second = second->next;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = second;
    }
};

int main() {
    LinkedList list;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        list.insert(value);
    }

    char choice;

    cout << "Do you want to create a loop? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
        list.createLoop();

    if (list.detectLoop())
        cout << "Loop exists in the linked list." << endl;
    else
        cout << "No loop exists in the linked list." << endl;

    return 0;
}
