#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
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

    void push(char ch)
    {
        Node* temp = new Node;
        temp->data = ch;
        temp->link = top;
        top = temp;
    }

    char pop()
    {
        if (top == 0)
        {
            return '\0';
        }

        Node* temp = top;
        char ch = temp->data;
        top = top->link;
        delete temp;

        return ch;
    }

    char peek()
    {
        if (top == 0)
        {
            return '\0';
        }

        return top->data;
    }

    bool isEmpty()
    {
        return top == 0;
    }
};

int priority(char op)
{
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '^')
    {
        return true;
    }

    return false;
}

string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // If character is an operand
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix = postfix + ch;
        }

        // If opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }

        // If closing bracket
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix = postfix + s.pop();
            }

            if (!s.isEmpty())
            {
                s.pop();
            }
        }

        // If operator
        else if (isOperator(ch))
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   priority(s.peek()) >= priority(ch))
            {
                postfix = postfix + s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty())
    {
        postfix = postfix + s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Postfix Expression: "
         << infixToPostfix(infix) << endl;

    return 0;
}
