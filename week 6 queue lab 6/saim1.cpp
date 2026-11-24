#include <iostream>
using namespace std;

class Que {
public:
    int size;      // default capacity
    int *q;        // array that holds queue elements
    int front;     // index of front of queue
    int rear;      // index of rear of queue

    Que() {        // default constructor
        size = 10;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    Que(int x) {   // overloaded constructor
        size = x;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free dynamically allocated memory
    ~Que() {
        delete[] q;
    }

    bool is_empty() {
        if (rear == -1)
            return true;
        else
            return false;
    }

    bool is_full() {
        if (rear == size - 1)
            return true;
        else
            return false;
    }

    void display() {
        if (is_empty()) {
            cout << "\nQueue is empty....";
        } else {
            for (int i = front; i <= rear; i++) {
                cout << "\nValue at index " << i << " is: " << q[i];
            }
        }
    }

    void enqueue(int x) {
        if (is_full()) {
            cout << "\nNo space";
        } else {
            if (is_empty()) {
                front = rear = 0;
            } else {
                rear++;
            }
            q[rear] = x;
        }
    }

    int dequeue() {
        if (is_empty()) {
            cout << "\nQueue is already empty";
            return -1;
        } else {
            int x = q[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
            return x;
        }
    }
};

int main() {
    Que q1;       // Default constructor: object of Que class with default size
    Que q2(5);    // Overloaded constructor: object of Que class (q2) with size 5
    Que q3(15);

    q1.enqueue(5);
    q2.enqueue(7);
    q3.enqueue(6);

    int x = q2.dequeue();
    cout << "\nDequeued element from q2 is: " << x;

    return 0;
}
