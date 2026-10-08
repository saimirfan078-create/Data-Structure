#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string expr) {
    stack<char> s; // Custom LinkedStack ke bajaye standard C++ stack library
    char ch;

    for (int i = 0; i < expr.length(); i++) {
        // Agar opening bracket ho toh stack mein push karein
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }

        // Agar closing bracket aaye aur stack empty ho, toh balanced nahi hai
        if (s.empty())
            return false;

        // Closing bracket ke muqable stack se top bracket check karein
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

    // Akhir mein agar stack empty hai toh saare brackets properly match ho gaye hain
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
