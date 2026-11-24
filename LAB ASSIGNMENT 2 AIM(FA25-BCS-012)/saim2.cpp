
#include <iostream> // Include input and output
using namespace std; // Use standard namespace

// Define a linked-list node
struct Node {
    int data; // Store element
    Node* next; // Point to next node

    Node(int value) {
        data = value; // Initialize data
        next = NULL; // Initialize link
    }
};

// Implement a stack using a linked list
class Stack {
private:
    Node* top; // Point to top node

public:
    Stack() {
        top = NULL; // Initialize empty stack
    }

    bool isEmpty() {
        return top == NULL; // Check empty stack
    }

    void push(int value) {
        Node* newNode = new Node(value); // Create node
        newNode->next = top; // Link new node to old top
        top = newNode; // Update top pointer
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Handle empty stack
        }

        Node* temp = top; // Store top node
        int value = temp->data; // Save its value
        top = top->next; // Move top to next node
        delete temp; // Free removed node
        return value; // Return removed value
    }

    ~Stack() {
        while (!isEmpty()) {
            pop(); // Delete all remaining nodes
        }
    }
};

// Implement a queue using two linked-list stacks
class Queue {
private:
    Stack S1, S2; // Create two stacks

public:
    void enqueue(int value) {
        S1.push(value); // Insert value into first stack
    }

    void dequeue() {
        if (S1.isEmpty() && S2.isEmpty()) {
            cout << "Queue is empty!\n"; // Handle empty queue
            return;
        }

        // Reverse elements when second stack is empty
        if (S2.isEmpty()) {
            while (!S1.isEmpty()) {
                S2.push(S1.pop()); // Transfer elements
            }
        }

        cout << "Dequeued: " << S2.pop() << endl; // Remove oldest value
    }
};

int main() {
    Queue q; // Create queue

    q.enqueue(10); // Insert 10
    q.enqueue(20); // Insert 20
    q.enqueue(30); // Insert 30
    q.enqueue(40); // Insert 40

    q.dequeue(); // Remove 10
    q.dequeue(); // Remove 20
    q.dequeue(); // Remove 30
    q.dequeue(); // Remove 40
    q.dequeue(); // Test empty queue

    return 0; // End program
}

