
#include <iostream> // Provides input and output operations
using namespace std; // Allows standard library names without std::

const int SIZE = 100; // Defines the maximum stack capacity

// Implements a stack using an array
class Stack {
private:
    int arr[SIZE]; // Stores stack elements
    int topIndex;  // Points to the top element

public:
    // Initializes an empty stack
    Stack() {
        topIndex = -1;
    }

    // Checks whether the stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Checks whether the stack is full
    bool isFull() {
        return topIndex == SIZE - 1;
    }

    // Inserts an element into the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++topIndex] = value;
    }

    // Removes and returns the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    // Returns the top element without removing it
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return arr[topIndex];
    }

    // Displays stack elements from bottom to top
    void display() {
        cout << "[ ";
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << "]";
    }
};

// Implements a queue using exactly two stacks
class MyQueue {
private:
    Stack s1, s2; // s1 receives new elements; s2 serves front elements

public:
    // Inserts an element at the rear of the queue
    void enqueue(int x) {
        if (s1.isFull()) {
            cout << "Queue capacity reached!" << endl;
            return;
        }
        s1.push(x);
    }

    // Moves elements to s2 when s2 is empty
    void transfer() {
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }
    }

    // Removes and returns the front element
    int dequeue() {
        if (s2.isEmpty()) {
            transfer();
        }

        if (s2.isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return s2.pop();
    }

    // Returns the front element without removing it
    int front() {
        if (s2.isEmpty()) {
            transfer();
        }

        if (s2.isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return s2.top();
    }

    // Checks whether both stacks are empty
    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }

    // Displays both internal stacks
    void displayState() {
        cout << "s1 = ";
        s1.display();

        cout << "\ns2 = ";
        s2.display();

        cout << "\nQueue (front to rear) = ";

        // Display s2 in reverse array order, followed by s1
        // The display order is reconstructed using the stack operations.
        MyQueue temp = *this;

        if (temp.isEmpty()) {
            cout << "Empty";
        } else {
            while (!temp.isEmpty()) {
                cout << temp.dequeue() << " ";
            }
        }

        cout << "\n------------------------" << endl;
    }
};

// Demonstrates queue operations
int main() {
    MyQueue q;

    cout << "Enqueue 15" << endl;
    q.enqueue(15);
    q.displayState();

    cout << "Enqueue 25" << endl;
    q.enqueue(25);
    q.displayState();

    cout << "Enqueue 35" << endl;
    q.enqueue(35);
    q.displayState();

    cout << "Dequeue: " << q.dequeue() << endl;
    q.displayState();

    cout << "Enqueue 45" << endl;
    q.enqueue(45);
    q.displayState();

    cout << "Front: " << q.front() << endl;
    q.displayState();

    cout << "Dequeue: " << q.dequeue() << endl;
    q.displayState();

    return 0; // Ends the program successfully
}

