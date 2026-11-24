
#include <iostream> // Include input and output
using namespace std; // Use standard namespace

// Define a linked-list node
struct Node {
    int data; // Store element
    Node* next; // Link to next node

    Node(int value) {
        data = value; // Initialize value
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
        return top == NULL; // Check whether stack is empty
    }

    void push(int value) {
        Node* node = new Node(value); // Create new node
        node->next = top; // Link new node to old top
        top = node; // Update top pointer
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Handle empty stack
        }

        Node* temp = top; // Save top node
        int value = temp->data; // Save its value
        top = top->next; // Move top to next node
        delete temp; // Free removed node
        return value; // Return removed value
    }

    void insertionSort() {
        // Extract stack elements into a temporary array
        int arr[100]; // Create temporary array
        int n = 0; // Initialize element count

        while (!isEmpty()) {
            arr[n++] = pop(); // Copy stack elements
        }

        // Sort values using insertion sort
        for (int i = 1; i < n; i++) {
            int key = arr[i]; // Store current value
            int j = i - 1; // Start from previous position

            // Shift elements larger than the current value
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j]; // Move larger value right
                j--; // Move to previous position
            }

            arr[j + 1] = key; // Insert value at correct position
        }

        // Push sorted values back onto the linked-list stack
        for (int i = 0; i < n; i++) {
            push(arr[i]); // Restore sorted values
        }
    }

    void display() {
        Node* current = top; // Start from top node

        while (current != NULL) {
            cout << current->data << " "; // Display value
            current = current->next; // Move to next node
        }
        cout << endl;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop(); // Delete all remaining nodes
        }
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

