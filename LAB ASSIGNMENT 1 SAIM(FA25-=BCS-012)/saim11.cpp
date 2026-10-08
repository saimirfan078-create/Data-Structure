#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string value) {
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

    void insert(string value) {
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

    void swapNodes() {
        Node* left = first;
        Node* right = last;

        while (left != NULL && right != NULL &&
               left != right && left->prev != right) {

            string temp = left->data;
            left->data = right->data;
            right->data = temp;

            left = left->next;
            right = right->prev;
        }
    }
};

int main() {
    DoublyLinkedList list;

    int n;
    string value;

    cout << "Enter number of desks: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter desk name: ";
        cin >> value;
        list.insert(value);
    }

    cout << "Original List: ";
    list.display();

    list.swapNodes();

    cout << "After Swapping: ";
    list.display();

    return 0;
}
