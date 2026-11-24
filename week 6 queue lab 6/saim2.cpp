#include <iostream>
using namespace std;

class CircularQueue {
public:
    int size;      // capacity of the queue
    int *q;        // array that holds queue elements
    int front;     // index of front of queue
    int rear;      // index of rear of queue

    CircularQueue() {        // default constructor
        size = 10;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    CircularQueue(int x) {   // overloaded constructor
        size = x;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free dynamically allocated memory
    ~CircularQueue() {
        delete[] q;
    }

    bool is_empty() {
        if (front == -1)
            return true;
        else
            return false;
    }

    bool is_full() {
        // Circular condition for full queue
        if ((rear + 1) % size == front)
            return true;
        else
            return false;
    }

    void display() {
        if (is_empty()) {
            cout << "\nQueue is empty....";
        } else {
            cout << "\nQueue elements: ";
            int i = front;
            while (true) {
                cout << q[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % size; // Wrap around using modulo
            }
        }
    }

    void enqueue(int x) {
        if (is_full()) {
            cout << "\nQueue is Full (Overflow)! Cannot insert " << x;
        } else {
            if (is_empty()) {
                front = rear = 0; // First element insertion
            } else {
                rear = (rear + 1) % size; // Wrap around if at end
            }
            q[rear] = x;
            cout << "\nInserted: " << x;
        }
    }

    int dequeue() {
        if (is_empty()) {
            cout << "\nQueue is already empty (Underflow)";
            return -1;
        } else {
            int x = q[front];
            if (front == rear) {
                front = rear = -1; // Queue becomes empty again
            } else {
                front = (front + 1) % size; // Wrap around if at end
            }
            return x;
        }
    }
};

int main() {
    // Create a circular queue of small size 3 to test wrapping
    CircularQueue cq(3);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30); // Queue is now full

    cq.display();

    // Dequeue two elements to free up space at the beginning
    cout << "\n\nDequeued: " << cq.dequeue();
    cout << "\nDequeued: " << cq.dequeue();

    cq.display();

    // Insert new elements to demonstrate wrapping around into freed spaces
    cout << "\n";
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    return 0;
}
