#include <iostream>
#include <string>
using namespace std;

// Node structure for Doubly Linked List
template <class T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Linked Deque Class
template <class T>
class LinkedDeque {
private:
    Node<T>* front; // Points to the front of the deque
    Node<T>* rear;  // Points to the rear of the deque

public:
    LinkedDeque() {
        front = NULL;
        rear = NULL;
    }

    // Destructor to free all allocated memory
    ~LinkedDeque() {
        while (!isEmpty()) {
            delete_fr_front_silent();
        }
    }

    bool isEmpty() {
        return (front == NULL);
    }

    // Insert an element at the beginning (front)
    void insert_at_beg(T x) {
        Node<T>* newNode = new Node<T>(x);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "\nInserted at beginning: " << x;
    }

    // Insert an element at the end (rear)
    void insert_at_end(T x) {
        Node<T>* newNode = new Node<T>(x);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << "\nInserted at end: " << x;
    }

    // Delete an element from the front
    void delete_fr_front() {
        if (isEmpty()) {
            cout << "\nDeletion not possible: Deque is empty!";
            return;
        }
        
        Node<T>* temp = front;
        cout << "\nDeleted from front: " << temp->data;

        front = front->next;
        if (front == NULL) {
            rear = NULL; // Deque is now empty
        } else {
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete an element from the rear
    void delete_fr_rear() {
        if (isEmpty()) {
            cout << "\nDeletion not possible: Deque is empty!";
            return;
        }
        
        Node<T>* temp = rear;
        cout << "\nDeleted from rear: " << temp->data;

        rear = rear->prev;
        if (rear == NULL) {
            front = NULL; // Deque is now empty
        } else {
            rear->next = NULL;
        }

        delete temp;
    }

    // Display elements from front to rear
    void show() {
        if (isEmpty()) {
            cout << "\nDeque is empty.";
            return;
        }
        
        cout << "\nDeque elements (Front to Rear): ";
        Node<T>* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }

private:
    // Silent deletion helper for destructor
    void delete_fr_front_silent() {
        if (!isEmpty()) {
            Node<T>* temp = front;
            front = front->next;
            if (front == NULL) {
                rear = NULL;
            } else {
                front->prev = NULL;
            }
            delete temp;
        }
    }
};

int main() {
    cout << "--- Testing Linked Deque ---";
    LinkedDeque<int> dq;

    // Test insertions
    dq.insert_at_end(10);
    dq.insert_at_end(20);
    dq.insert_at_beg(5);
    dq.insert_at_beg(1);

    // Current state: 1 -> 5 -> 10 -> 20
    dq.show();

    // Test deletions
    dq.delete_fr_front(); // Removes 1
    dq.delete_fr_rear();  // Removes 20

    // Current state: 5 -> 10
    dq.show();

    // Insert more and show dynamic growth
    dq.insert_at_end(30);
    dq.show();

    cout << "\n";
    return 0;
}

