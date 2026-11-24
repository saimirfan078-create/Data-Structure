
#include <iostream>  // For input and output
#include <stack>    // For using stack
using namespace std;

int main() {

    stack<int> Q1;  // First stack
    stack<int> Q2;  // Second stack

    // Push values into Q1
    Q1.push(10);
    Q1.push(20);
    Q1.push(30);
    Q1.push(40);

    // Transfer values from Q1 to Q2 until Q1 is empty
    while (!Q1.empty()) {
        Q2.push(Q1.top());  // Push top value of Q1 into Q2
        Q1.pop();           // Remove top value from Q1
    }

    // Transfer values back from Q2 to Q1
    while (!Q2.empty()) {
        Q1.push(Q2.top());  // Push top value of Q2 into Q1
        Q2.pop();           // Remove top value from Q2
    }

    // Display values in reverse order
    cout << "Output: ";

    while (!Q1.empty()) {
        cout << Q1.top() << " ";
        Q1.pop();
    }

    return 0;
}


