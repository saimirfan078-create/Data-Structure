
#include <iostream>  // For input and output
using namespace std;

const int SIZE = 10;

// Queue class
class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    // Constructor
    Queue() {
        front = 0;
        rear = -1;
    }

    // Check whether queue is empty
    bool isEmpty() {
        return front > rear;
    }

    // Insert a value into queue
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full!" << endl;
            return;
        }

        arr[++rear] = value;
    } 
    
    // Remove and return a value
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front++];
    }
};

int main() {
    Queue Q1, Q2;

    // Insert values into Q1
    Q1.enqueue(10);
    Q1.enqueue(20);
    Q1.enqueue(30);
    Q1.enqueue(40);

    // Transfer values from Q1 to Q2
    while (!Q1.isEmpty()) {
        Q2.enqueue(Q1.dequeue());
    }

    // Transfer values back to Q1 in reverse order
    // First store Q2 values in an array
    int temp[SIZE];
    int count = 0;

    while (!Q2.isEmpty()) {
        temp[count++] = Q2.dequeue();
    }

    // Enqueue values in reverse order into Q1
    for (int i = count - 1; i >= 0; i--) {
        Q1.enqueue(temp[i]);
    }

    // Display values
    cout << "Output: ";
    while (!Q1.isEmpty()) {
        cout << Q1.dequeue() << " ";
    }

    return 0;
}

