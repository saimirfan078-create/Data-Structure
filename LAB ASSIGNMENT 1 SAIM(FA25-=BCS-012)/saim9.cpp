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

    void deleteAll(int key) {
        while (first != NULL && first->data == key) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }

        Node* current = first;

        while (current != NULL && current->next != NULL) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            else {
                current = current->next;
            }
        }
    }
};

int main() {
    LinkedList list;

    int n, value, key;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book ID: ";
        cin >> value;
        list.insert(value);
    }

    cout << "Original List: ";
    list.display();

    cout << "Enter ID to delete: ";
    cin >> key;

    list.deleteAll(key);

    cout << "After Deletion: ";
    list.display();

    return 0;
}
