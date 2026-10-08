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

class CircularLinkedList {
public:
    Node* first;
    Node* last;

    CircularLinkedList() {
        first = NULL;
        last = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (first == NULL) {
            first = last = newNode;
            newNode->next = first;
            return;
        }

        last->next = newNode;
        last = newNode;
        last->next = first;
    }

    int josephus(int m) {
        if (first == NULL)
            return -1;

        Node* previous = last;
        Node* current = first;

        while (current->next != current) {

            for (int i = 1; i < m; i++) {
                previous = current;
                current = current->next;
            }

            previous->next = current->next;

            if (current == first)
                first = current->next;

            if (current == last)
                last = previous;

            delete current;

            current = previous->next;
        }

        first = current;
        last = current;

        return current->data;
    }
};

int main() {
    CircularLinkedList list;

    int n, m;

    cout << "Enter number of persons: ";
    cin >> n;

    cout << "Enter M: ";
    cin >> m;

    for (int i = 1; i <= n; i++) {
        list.insert(i);
    }

    int survivor = list.josephus(m);

    cout << "Survivor is person: " << survivor << endl;

    return 0;
}
