
#include <iostream> // Include input and output
using namespace std; // Use standard namespace

const int SIZE = 100; // Define maximum queue size

// Create an array-based queue
class Queue {
public:
    int arr[SIZE]; // Store elements
    int n; // Store number of elements

    Queue() {
        n = 0; // Initialize empty queue
    }

    void enqueue(int value) {
        if (n < SIZE) {
            arr[n++] = value; // Insert at rear
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " "; // Display each element
        }
        cout << endl;
    }

    void bubbleSort() {
        // Compare adjacent elements in every pass
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap elements when they are out of order
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
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
    q.display(); // Display original queue

    q.bubbleSort(); // Sort queue elements

    cout << "After sorting: ";
    q.display(); // Display sorted queue

    return 0; // End program
}

