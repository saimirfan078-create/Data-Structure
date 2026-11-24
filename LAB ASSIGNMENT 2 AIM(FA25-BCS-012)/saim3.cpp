
#include <iostream> // Include input and output
using namespace std; // Use standard namespace

const int SIZE = 100; // Define queue capacity

// Implement a queue using an array
class Queue {
private:
    int arr[SIZE]; // Store queue elements
    int front, rear, count; // Track queue positions and size

public:
    Queue() {
        front = 0; // Set front position
        rear = -1; // Set rear before first element
        count = 0; // Initialize empty queue
    }

    bool isEmpty() {
        return count == 0; // Check empty queue
    }

    bool isFull() {
        return count == SIZE; // Check full queue
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!\n"; // Handle overflow
            return;
        }

        rear = (rear + 1) % SIZE; // Move rear circularly
        arr[rear] = value; // Insert element
        count++; // Increase queue size
    }

    int dequeue() {
        if (isEmpty()) {
            return -1; // Handle empty queue
        }

        int value = arr[front]; // Save front element
        front = (front + 1) % SIZE; // Move front circularly
        count--; // Decrease queue size
        return value; // Return removed element
    }
};

// Implement stack using two queues
class Stack {
private:
    Queue Q1, Q2; // Create two queues

public:
    void push(int value) {
        Q2.enqueue(value); // Insert new value into Q2

        // Move all older elements behind the new value
        while (!Q1.isEmpty()) {
            Q2.enqueue(Q1.dequeue()); // Transfer elements
        }

        // Swap queues so Q1 holds the stack
        Queue temp = Q1;
        Q1 = Q2;
        Q2 = temp;
    }

    void pop() {
        if (Q1.isEmpty()) {
            cout << "Stack is empty!\n"; // Handle underflow
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
    s.pop(); // Test empty stack

    return 0; // End program
}


