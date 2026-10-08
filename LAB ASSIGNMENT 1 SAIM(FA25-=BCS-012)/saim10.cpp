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

    void display() {
        Node* temp = first;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void swapPairs() {
        if (first == NULL || first->next == NULL)
            return;

        Node* previous = NULL;
        Node* current = first;

        first = first->next;

        while (current != NULL && current->next != NULL) {
            Node* second = current->next;
            Node* nextPair = second->next;

            second->next = current;
            current->next = nextPair;

            if (previous != NULL)
                previous->next = second;

            previous = current;
            current = nextPair;
        }
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

    list.swapPairs();

    cout << "After Pair Swapping: ";
    list.display();

    return 0;
}
