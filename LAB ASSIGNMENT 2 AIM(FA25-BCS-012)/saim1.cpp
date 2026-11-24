
#include <iostream> // Include input and output functions
using namespace std; // Use standard namespace

const int SIZE = 100; // Define maximum stack size

// Create an array-based stack
class Stack {
private:
    int arr[SIZE]; // Store stack elements
    int top;       // Track the top element

public:
    Stack() {
        top = -1; // Initialize an empty stack
    }

    bool isEmpty() {
        return top == -1; // Check whether stack is empty
    }

    bool isFull() {
        return top == SIZE - 1; // Check whether stack is full
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow!\n"; // Display overflow message
            return;
        }
        arr[++top] = value; // Insert value at the top
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Return error value if stack is empty
        }
        return arr[top--]; // Remove and return top element
    }

    int peek() {
        return arr[top]; // Return top element without removing it
    }
};

// Implement a queue using two stacks
class Queue {
private:
    Stack S1, S2; // Create two stacks

public:
    void enqueue(int value) {
        S1.push(value); // Insert new value into first stack
    }

    void dequeue() {
        if (S1.isEmpty() && S2.isEmpty()) {
            cout << "Queue is empty!\n"; // Handle empty queue
            return;
        }

        // Transfer elements only when second stack is empty
        if (S2.isEmpty()) {
            while (!S1.isEmpty()) {
                S2.push(S1.pop()); // Reverse the element order
            }
        }

        cout << "Dequeued: " << S2.pop() << endl; // Remove oldest value
    }

    void display() {
        // Display the queue in FIFO order
        if (!S2.isEmpty()) {
            cout << "Queue: ";
            Stack temp; // Create a temporary stack
            while (!S2.isEmpty()) {
                int value = S2.pop(); // Remove top element
                cout << value << " "; // Display element
                temp.push(value); // Save element temporarily
            }
            while (!temp.isEmpty()) {
                S2.push(temp.pop()); // Restore second stack
            }
            Stack temp2; // Temporarily reverse first stack for display
            while (!S1.isEmpty()) {
                temp2.push(S1.pop()); // Transfer elements
            }
            while (!temp2.isEmpty()) {
                int value = temp2.pop(); // Get next queue element
                cout << value << " "; // Display element
                S1.push(value); // Restore first stack
            }
            cout << endl;
        } else {
            cout << "Queue: ";
            Stack temp; // Create temporary stack
            while (!S1.isEmpty()) {
                temp.push(S1.pop()); // Transfer elements
            }
            while (!temp.isEmpty()) {
                int value = temp.pop(); // Retrieve element
                cout << value << " "; // Display in queue order
                S1.push(value); // Restore original stack
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q; // Create a queue

    q.enqueue(10); // Insert 10
    q.enqueue(20); // Insert 20
    q.enqueue(30); // Insert 30
    q.enqueue(40); // Insert 40

    q.display(); // Display queue elements
    q.dequeue(); // Remove 10
    q.dequeue(); // Remove 20
    q.display(); // Display remaining elements

    return 0; // End program
}

