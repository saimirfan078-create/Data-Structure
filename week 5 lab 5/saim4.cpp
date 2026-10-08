#include <iostream>
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

    bool isEmpty()
    {
        return top == 0;
    }
};

bool isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return true;

    if (open == '[' && close == ']')
        return true;

    if (open == '{' && close == '}')
        return true;

    return false;
}

bool isBalanced(string expression)
{
    Stack s;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }

        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (s.isEmpty())
            {
                return false;
            }

            char open = s.pop();

            if (!isMatching(open, ch))
            {
                return false;
            }
        }
    }

    if (s.isEmpty())
        return true;
    else
        return false;
}

int main()
{
    string expression;

    cout << "Enter brackets: ";
    cin >> expression;

    if (isBalanced(expression))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
