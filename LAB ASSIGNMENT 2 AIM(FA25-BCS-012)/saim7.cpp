
#include <iostream> // Include input and output
using namespace std; // Use standard namespace

const int SIZE = 100; // Define queue capacity

// Implement an array-based queue
class Queue {
public:
    int arr[SIZE]; // Store elements
    int n; // Track number of elements

    Queue() {
        n = 0; // Initialize empty queue
    }

    void enqueue(int value) {
        if (n < SIZE) {
            arr[n++] = value; // Insert at rear
        }
    }

    void selectionSort() {
        // Select the minimum element for each position
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i; // Assume current element is minimum

            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j; // Update minimum index
                }
            }

            // Swap minimum element into correct position
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " "; // Display elements
        }
        cout << endl;
    }
};

int main() {
    Queue q; // Create queue

    q.enqueue(40); // Insert 40
    q.enqueue(10); // Insert 10
    q.enqueue(30); // Insert 30
    q.enqueue(20); // Insert 20

    cout << "Before sorting: ";
    q.display(); // Display original elements

    q.selectionSort(); // Sort elements

    cout << "After sorting: ";
    q.display(); // Display sorted elements

    return 0; // End program
}

