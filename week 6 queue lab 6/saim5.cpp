#include <iostream>
#include <string>
using namespace std;

// Node structure to represent each element in the queue
template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

// Linked Queue Class
template <class T>
class LinkedQueue {
private:
    Node<T>* front; // Points to the first element (dequeue end)
    Node<T>* rear;  // Points to the last element (enqueue end)

public:
    LinkedQueue() {
        front = NULL;
        rear = NULL;
    }

    // Destructor to free all allocated memory and prevent memory leaks
    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeueSilent();
        }
    }

    bool isEmpty() {
        return (front == NULL);
    }

    // Insert an element at the rear of the queue
    void enqueue(T x) {
        Node<T>* newNode = new Node<T>(x);
        
        if (isEmpty()) {
            front = rear = newNode; // First node being inserted
        } else {
            rear->next = newNode;   // Link new node at the end
            rear = newNode;         // Move rear pointer forward
        }
        cout << "\nEnqueued: " << x;
    }

    // Remove and return an element from the front of the queue
    T dequeue() {
        if (isEmpty()) {
            cout << "\nQueue Underflow! Queue is empty.";
            return T(); // Returns default value for type T (0, '\0', or "")
        }
        
        Node<T>* temp = front;
        T val = temp->data;
        
        front = front->next; // Move front to the next node

        if (front == NULL) {
            rear = NULL;  // If queue becomes empty, reset rear as well
        }

        delete temp; // Free memory of the old front node
        return val;
    }

    // Helper for destructor to avoid printing delete messages during destruction
    void dequeueSilent() {
        if (!isEmpty()) {
            Node<T>* temp = front;
            front = front->next;
            if (front == NULL) rear = NULL;
            delete temp;
        }
    }

    // Display all elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "\nQueue is empty.";
            return;
        }
        
        cout << "\nQueue elements (Front to Rear): ";
        Node<T>* current = front;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    // Testing with integers
    cout << "--- Testing Integer Linked Queue ---";
    LinkedQueue<int> q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    q1.display();

    cout << "\n\nDequeued value: " << q1.dequeue();
    cout << "\nDequeued value: " << q1.dequeue();

    q1.display();

    q1.enqueue(40);
    q1.enqueue(50);
    q1.display();

    // Testing with strings to prove template flexibility
    cout << "\n\n--- Testing String Linked Queue ---";
    LinkedQueue<string> q2;
    q2.enqueue("Hello");
    q2.enqueue("Dynamic");
    q2.enqueue("Queue");
    q2.display();

    cout << "\n\nDequeued value: " << q2.dequeue();
    q2.display();
    cout << "\n";

    return 0;
}
