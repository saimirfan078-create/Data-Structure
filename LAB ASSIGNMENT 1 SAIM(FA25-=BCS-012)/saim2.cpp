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

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display() {
        Node* temp = first;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void reverseList() {
        Node* previous = NULL;
        Node* current = first;
        Node* nextNode = NULL;

        while (current != NULL) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        first = previous;
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

    cout << "Original List: ";
    list.display();

    list.reverseList();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
