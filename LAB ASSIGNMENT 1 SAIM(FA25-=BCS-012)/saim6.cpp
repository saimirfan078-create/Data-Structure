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

    void separateEvenOdd() {
        Node* evenFirst = NULL;
        Node* evenLast = NULL;

        Node* oddFirst = NULL;
        Node* oddLast = NULL;

        Node* temp = first;

        while (temp != NULL) {
            Node* nextNode = temp->next;
            temp->next = NULL;

            if (temp->data % 2 == 0) {
                if (evenFirst == NULL) {
                    evenFirst = temp;
                    evenLast = temp;
                }
                else {
                    evenLast->next = temp;
                    evenLast = temp;
                }
            }
            else {
                if (oddFirst == NULL) {
                    oddFirst = temp;
                    oddLast = temp;
                }
                else {
                    oddLast->next = temp;
                    oddLast = temp;
                }
            }

            temp = nextNode;
        }

        cout << "Even List: ";

        temp = evenFirst;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;

        cout << "Odd List: ";

        temp = oddFirst;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
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

    list.separateEvenOdd();

    return 0;
}
