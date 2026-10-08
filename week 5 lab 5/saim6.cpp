#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = 0;
    }

    void push(int value)
    {
        Node* temp = new Node;
        temp->data = value;
        temp->link = top;
        top = temp;
    }

    int pop()
    {
        if (top == 0)
        {
            return 0;
        }

        Node* temp = top;
        int value = temp->data;
        top = top->link;
        delete temp;

        return value;
    }

    bool isEmpty()
    {
        return top == 0;
    }
};

int main()
{
    Stack s;
    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    int values[26];

    cout << "\nEnter values of variables:\n";

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            int index = ch - 'A';

            if (values[index] == 0)
            {
                cout << ch << " = ";
                cin >> values[index];
            }
        }
    }

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // If character is an operand
        if (ch >= 'A' && ch <= 'Z')
        {
            s.push(values[ch - 'A']);
        }

        // If character is an operator
        else
        {
            int value2 = s.pop();
            int value1 = s.pop();

            if (ch == '+')
                s.push(value1 + value2);

            else if (ch == '-')
                s.push(value1 - value2);

            else if (ch == '*')
                s.push(value1 * value2);

            else if (ch == '/')
                s.push(value1 / value2);
        }
    }

    cout << "\nResult = " << s.pop() << endl;

    return 0;
}
