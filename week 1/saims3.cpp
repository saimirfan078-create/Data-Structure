#include <iostream>
using namespace std;

const int SIZE = 100;
int listArray[SIZE];
int count = 0;

void insertEnd(int value)
{
    listArray[count] = value;
    count++;
}

void display()
{
    cout << "List: ";

    for (int i = 0; i < count; i++)
    {
        cout << listArray[i] << " ";
    }

    cout << endl;
}

void linearSearch(int value)
{
    int position = -1;

    for (int i = 0; i < count; i++)
    {
        if (listArray[i] == value)
        {
            position = i;
            break;
        }
    }

    if (position != -1)
        cout << "Value found at position " << position + 1 << endl;
    else
        cout << "Value not found." << endl;
}

int main()
{
    int n, value, searchValue;

    cout << "How many values do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;

        insertEnd(value);
    }

    display();

    cout << "Enter value to search: ";
    cin >> searchValue;

    linearSearch(searchValue);

    return 0;
}
