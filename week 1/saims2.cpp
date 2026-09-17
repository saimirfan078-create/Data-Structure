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

void insertStart(int value)
{
    for (int i = count; i > 0; i--)
    {
        listArray[i] = listArray[i - 1];
    }

    listArray[0] = value;
    count++;
}

void insertAfter(int oldValue, int value)
{
    int pos = -1;

    for (int i = 0; i < count; i++)
    {
        if (listArray[i] == oldValue)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (int i = count; i > pos + 1; i--)
        {
            listArray[i] = listArray[i - 1];
        }

        listArray[pos + 1] = value;
        count++;
    }
}

void insertBefore(int oldValue, int value)
{
    int pos = -1;

    for (int i = 0; i < count; i++)
    {
        if (listArray[i] == oldValue)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (int i = count; i > pos; i--)
        {
            listArray[i] = listArray[i - 1];
        }

        listArray[pos] = value;
        count++;
    }
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

void deleteEnd()
{
    if (count > 0)
        count--;
}

void deleteStart()
{
    if (count > 0)
    {
        for (int i = 0; i < count - 1; i++)
        {
            listArray[i] = listArray[i + 1];
        }

        count--;
    }
}

void deleteSpecific(int value)
{
    int pos = -1;

    for (int i = 0; i < count; i++)
    {
        if (listArray[i] == value)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (int i = pos; i < count - 1; i++)
        {
            listArray[i] = listArray[i + 1];
        }

        count--;
    }
}

int main()
{
    int choice, value, oldValue;

    do
    {
        cout << "\n1. Insert at end" << endl;
        cout << "2. Insert at start" << endl;
        cout << "3. Insert after value" << endl;
        cout << "4. Insert before value" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete from start" << endl;
        cout << "8. Delete specific value" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertEnd(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertStart(value);
            break;

        case 3:
            cout << "Enter value after which to insert: ";
            cin >> oldValue;

            cout << "Enter new value: ";
            cin >> value;

            insertAfter(oldValue, value);
            break;

        case 4:
            cout << "Enter value before which to insert: ";
            cin >> oldValue;

            cout << "Enter new value: ";
            cin >> value;

            insertBefore(oldValue, value);
            break;

        case 5:
            display();
            break;

        case 6:
            deleteEnd();
            break;

        case 7:
            deleteStart();
            break;

        case 8:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteSpecific(value);
            break;

        case 9:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 9);

    return 0;
}
