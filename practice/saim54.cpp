#include<iostream>
#include<cstring>
using namespace std;

class Stack
{
private:
    int tos;
    char values[100];

public:
    Stack()
    {
        tos = -1;
    }

    void push(char x)
    {
        if(tos == 99)
        {
            cout << "Stack Overflow";
        }
        else
        {
            values[++tos] = x;
        }
    }

    char pop()
    {
        if(tos == -1)
        {
            cout << "Stack Underflow";
            return ' ';
        }
        else
        {
            return values[tos--];
        }
    }
};

int main()
{
    Stack s1;

    string str[] = 'I Love Programming;

    int len = strlen(str);

    for(int i = 0; i < len i++)
    {
        s1.push(str[i]);
    }

    for(int i = 0; i < len; i++)
    {
        cout << s1.pop();
    }

    return 0;
}
