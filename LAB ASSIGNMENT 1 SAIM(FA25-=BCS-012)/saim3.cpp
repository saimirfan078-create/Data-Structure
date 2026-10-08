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

    void removeDuplicates() {
        Node* current = first;

        while (current != NULL) {
            Node* previous = current;
            Node* temp = current->next;

            while (temp != NULL) {
                if (temp->data == current->data) {
                    previous->next = temp->next;
                    delete temp;
                    temp = previous->next;
                }
                else {
                    previous = temp;
                    temp = temp->next;
                }
            }

            current = current->next;
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

    list.removeDuplicates();

    cout << "After Removing Duplicates: ";
    list.display();

    return 0;
}
