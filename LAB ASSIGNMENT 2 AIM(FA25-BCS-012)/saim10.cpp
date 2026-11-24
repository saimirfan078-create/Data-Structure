
#include <iostream> // Include input and output
using namespace std; // Use standard namespace

const int SIZE = 100; // Define maximum stack size

// Implement a stack using an array
class Stack {
private:
    int arr[SIZE]; // Store stack elements
    int top; // Track top position

public:
    Stack() {
        top = -1; // Initialize empty stack
    }

    bool isEmpty() {
        return top == -1; // Check whether stack is empty
    }

    bool isFull() {
        return top == SIZE - 1; // Check whether stack is full
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full!\n"; // Handle overflow
            return;
        }

        arr[++top] = value; // Insert value at top
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Handle empty stack
        }

        return arr[top--]; // Remove and return top element
    }

    void insertionSort() {
        // Extract stack elements into a temporary array
        int temp[SIZE]; // Create temporary array
        int n = 0; // Count elements

        while (!isEmpty()) {
            temp[n++] = pop(); // Copy elements from stack
        }

        // Perform insertion sort in ascending order
        for (int i = 1; i < n; i++) {
            int key = temp[i]; // Store current value
            int j = i - 1; // Start from previous position

            // Shift larger values one position to the right
            while (j >= 0 && temp[j] > key) {
                temp[j + 1] = temp[j]; // Shift larger element
                j--; // Move backward
            }

            temp[j + 1] = key; // Insert value at correct position
        }

        // Push sorted values back into the stack
        for (int i = 0; i < n; i++) {
            push(temp[i]); // Restore sorted values
        }
    }

    void display() {
        // Display elements from top to bottom
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " "; // Print stack element
        }
        cout << endl;
    }
};

int main() {
    Stack s; // Create stack

    s.push(40); // Push 40
    s.push(10); // Push 10
    s.push(30); // Push 30
    s.push(20); // Push 20

    cout << "Before sorting (top to bottom): ";
    s.display(); // Display original stack

    s.insertionSort(); // Sort elements

    cout << "After sorting (top to bottom): ";
    s.display(); // Display sorted stack

    return 0; // End program
}

