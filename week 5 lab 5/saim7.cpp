#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string expr) {
    stack<char> s; 
    char ch;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }
        if (s.empty())
            return false;
        switch (expr[i]) {
            case ')':
                ch = s.top();
                s.pop();
                if (ch == '{' || ch == '[')
                    return false;
                break;

            case '}':
                ch = s.top();
                s.pop();
                if (ch == '(' || ch == '[')
                    return false;
                break;

            case ']':
                ch = s.top();
                s.pop();
                if (ch == '(' || ch == '{')
                    return false;
                break;
        }
    }
    return s.empty();
}

int main() {
    string expr = "[{}(){()}]";

    if (isBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
