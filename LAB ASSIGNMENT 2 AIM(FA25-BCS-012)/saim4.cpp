
#include <iostream> // Include input and output
using namespace std; // Use standard namespace

// Define a queue node
struct Node {
    int data; // Store value
    Node* next; // Point to next node

    Node(int value) {
        data = value; // Initialize value
        next = NULL; // Initialize link
    }
};

// Implement a linked-list queue
class Queue {
private:
    Node* front; // Point to first node
    Node* rear; // Point to last node

public:
    Queue() {
        front = rear = NULL; // Initialize empty queue
    }

    bool isEmpty() {
        return front == NULL; // Check empty queue
    }

    void enqueue(int value) {
        Node* node = new Node(value); // Create node

        if (isEmpty()) {
            front = rear = node; // Set both pointers
        } else {
            rear->next = node; // Attach node at rear
            rear = node; // Update rear pointer
        }
    }

    int dequeue() {
        if (isEmpty()) {
            return -1; // Handle empty queue
        }

        Node* temp = front; // Save front node
        int value = temp->data; // Save its value
        front = front->next; // Move front forward

        if (front == NULL) {
            rear = NULL; // Reset rear when queue becomes empty
        }

        delete temp; // Delete removed node
        return value; // Return removed value
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue(); // Free remaining nodes
        }
    }
};

// Implement stack using two linked-list queues
class Stack {
private:
    Queue Q1, Q2; // Create two queues

public:
    void push(int value) {
        Q2.enqueue(value); // Insert newest value first

        // Move older elements behind the newest value
        while (!Q1.isEmpty()) {
            Q2.enqueue(Q1.dequeue()); // Transfer old values
        }

        // Swap queues
        Queue temp = Q1;
        Q1 = Q2;
        Q2 = temp;
    }

    void pop() {
        if (Q1.isEmpty()) {
            cout << "Stack is empty!\n"; // Handle empty stack
            return;
        }

        cout << "Popped: " << Q1.dequeue() << endl; // Remove top value
    }
};

int main() {
    Stack s; // Create stack

    s.push(10); // Push 10
    s.push(20); // Push 20
    s.push(30); // Push 30
    s.push(40); // Push 40

    s.pop(); // Remove 40
    s.pop(); // Remove 30
    s.pop(); // Remove 20
    s.pop(); // Remove 10

    return 0; // End program
}

