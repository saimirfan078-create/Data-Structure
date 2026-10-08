#include <iostream>
#include <cstring> // strlen ke liye

using namespace std;

struct Node {
    char data;
    Node* link;
};

class Stack {
private:
    Node* head;

public:
    Stack() {
        head = NULL;
    }

    void push(char e) {
        Node* temp = new Node;
        temp->data = e;
        temp->link = head;
        head = temp;
    }

    char pop() {
        if (head == NULL) {
            cout << "\nStack is Empty .... Underflow Condition\n";
            return '\0';
        } else {
            Node* temp = head;
            char T = temp->data;
            head = temp->link;
            delete temp;
            return T;
        }
    }
};

int main() {
    Stack s1;
    char str[] = "I Love Programming";
    int len = strlen(str);

    // Characters ko stack me push karna
    for (int i = 0; i < len; i++) {
        s1.push(str[i]);
    }

    // Stack se characters pop karke screen par print karna (String reverse ho jayegi)
    for (int i = 0; i < len; i++) {
        cout << s1.pop();
    }

    cout << endl;
    return 0;
}
