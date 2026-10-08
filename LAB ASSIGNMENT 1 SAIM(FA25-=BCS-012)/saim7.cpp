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

    Node* reversePart(Node* start, int count) {
        Node* previous = NULL;
        Node* current = start;
        Node* nextNode = NULL;

        for (int i = 0; i < count && current != NULL; i++) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        start->next = current;

        return previous;
    }

    void reverseHalves() {
        int count = 0;
        Node* temp = first;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (count < 2)
            return;

        int half = count / 2;

        Node* secondHalf = first;

        for (int i = 1; i < half; i++)
            secondHalf = secondHalf->next;

        Node* secondStart = secondHalf->next;
        secondHalf->next = NULL;

        Node* firstStart = reversePart(first, half);

        if (count % 2 == 0) {
            Node* temp1 = firstStart;

            while (temp1->next != NULL)
                temp1 = temp1->next;

            Node* secondStartReversed = reversePart(secondStart, half);

            temp1->next = secondStartReversed;
            first = firstStart;
        }
        else {
            int secondCount = count - half;

            Node* secondStartReversed = reversePart(secondStart, secondCount);

            Node* temp1 = firstStart;

            while (temp1->next != NULL)
                temp1 = temp1->next;

            temp1->next = secondStartReversed;

            first = firstStart;
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

    list.reverseHalves();

    cout << "After Reversing Halves: ";
    list.display();

    return 0;
}
