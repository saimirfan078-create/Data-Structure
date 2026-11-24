
#include <iostream> // Include input and output
using namespace std; // Use standard namespace

// Define a linked-list node
struct Node {
    int data; // Store element
    Node* next; // Link to next node

    Node(int value) {
        data = value; // Initialize data
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
        return front == NULL; // Check if empty
    }

    void enqueue(int value) {
        Node* node = new Node(value); // Create node

        if (isEmpty()) {
            front = rear = node; // Set first and last node
        } else {
            rear->next = node; // Attach at end
            rear = node; // Update rear
        }
    }

    int dequeue() {
        if (isEmpty()) {
            return -1; // Handle empty queue
        }

        Node* temp = front; // Save front node
        int value = temp->data; // Save its value
        front = front->next; // Move front pointer

        if (front == NULL) {
            rear = NULL; // Reset rear if empty
        }

        delete temp; // Delete removed node
        return value; // Return removed value
    }

    void bubbleSort() {
        if (isEmpty()) return; // Stop for empty queue

        // Count the number of nodes
        int n = 0;
        Node* current = front;
        while (current != NULL) {
            n++; // Increase node count
            current = current->next; // Move forward
        }

        // Perform bubble sort by swapping node data
        for (int i = 0; i < n - 1; i++) {
            current = front; // Start from first node

            for (int j = 0; j < n - i - 1; j++) {
                if (current->data > current->next->data) {
                    // Swap adjacent node values
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                }
                current = current->next; // Move to next node
            }
        }
    }

    void display() {
        Node* current = front; // Start from first node

        while (current != NULL) {
            cout << current->data << " "; // Print value
            current = current->next; // Move forward
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue(); // Free all nodes
        }
    }
};

int main() {
    Queue q; // Create queue

    q.enqueue(40); // Insert 40
    q.enqueue(10); // Insert 10
    q.enqueue(30); // Insert 30
    q.enqueue(20); // Insert 20

    cout << "Before sorting: ";
    q.display(); // Display original values

    q.bubbleSort(); // Sort queue elements

    cout << "After sorting: ";
    q.display(); // Display sorted values

    return 0; // End program
}

