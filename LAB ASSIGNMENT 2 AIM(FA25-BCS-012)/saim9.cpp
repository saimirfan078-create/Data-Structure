
#include <iostream> // Include input and output
using namespace std; // Use standard namespace

// Define a node
struct Node {
    int data; // Store element
    Node* next; // Link to next node

    Node(int value) {
        data = value; // Initialize value
        next = NULL; // Initialize link
    }
};

// Implement a linked-list queue
class Queue {
private:
    Node* front; // First node
    Node* rear; // Last node

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
            front = rear = node; // Initialize both pointers
        } else {
            rear->next = node; // Attach at rear
            rear = node; // Update rear
        }
    }

    int dequeue() {
        if (isEmpty()) return -1; // Handle empty queue

        Node* temp = front; // Save first node
        int value = temp->data; // Save value
        front = front->next; // Move front forward

        if (front == NULL) rear = NULL; // Reset rear if empty

        delete temp; // Free removed node
        return value; // Return removed value
    }

    void selectionSort() {
        // Visit each node as the start of the unsorted part
        for (Node* current = front; current != NULL;
             current = current->next) {
            Node* minNode = current; // Assume current is minimum

            // Find the minimum value in the remaining nodes
            for (Node* nextNode = current->next;
                 nextNode != NULL; nextNode = nextNode->next) {
                if (nextNode->data < minNode->data) {
                    minNode = nextNode; // Update minimum node
                }
            }

            // Swap values, keeping the linked-list structure intact
            int temp = current->data;
            current->data = minNode->data;
            minNode->data = temp;
        }
    }

    void display() {
        Node* current = front; // Start from front

        while (current != NULL) {
            cout << current->data << " "; // Display value
            current = current->next; // Move to next node
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) dequeue(); // Delete remaining nodes
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

    q.selectionSort(); // Sort queue elements

    cout << "After sorting: ";
    q.display(); // Display sorted values

    return 0; // End program
}

