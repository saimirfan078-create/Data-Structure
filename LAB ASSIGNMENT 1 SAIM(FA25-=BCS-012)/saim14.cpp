#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* first;
    Node* last;

    DoublyLinkedList() {
        first = NULL;
        last = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (first == NULL) {
            first = last = newNode;
            return;
        }

        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }

    void display() {
        Node* temp = first;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void specialPattern() {
        if (first == NULL || first->next == NULL ||
            first->next->next == NULL)
            return;

        Node* left = first->next;
        Node* right = last->prev;

        while (left != NULL && right != NULL &&
               left != right && left->next != right) {

            int temp = left->data;
            left->data = right->data;
            right->data = temp;

            left = left->next->next;
            right = right->prev->prev;
        }
    }
};

int main() {
    DoublyLinkedList list;

    int n, value;

    cout << "Enter number of seats: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter seat number: ";
        cin >> value;
        list.insert(value);
    }

    cout << "Original List: ";
    list.display();

    list.specialPattern();

    cout << "After Special Pattern: ";
    list.display();

    return 0;
}
