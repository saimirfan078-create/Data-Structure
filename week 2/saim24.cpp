#include <iostream>
#include <cmath>
using namespace std;

const int CAPACITY = 20;

struct ArrayList
{
    int data[CAPACITY];
    int size = 0;
};

// Insert at End
bool insertEnd(ArrayList &list, int value)
{
    if (list.size == CAPACITY)
    {
        return false;
    }

    list.data[list.size] = value;
    list.size++;

    return true;
}

// Insert at Beginning
bool insertAtBeginning(ArrayList &list, int value)
{
    if (list.size == CAPACITY)
    {
        return false;
    }

    for (int i = list.size; i > 0; i--)
    {
        list.data[i] = list.data[i - 1];
    }

    list.data[0] = value;
    list.size++;

    return true;
}

// Delete at Position
bool deleteAtPosition(ArrayList &list, int position)
{
    if (position < 0 || position >= list.size)
    {
        return false;
    }

    for (int i = position; i < list.size - 1; i++)
    {
        list.data[i] = list.data[i + 1];
    }

    list.size--;

    return true;
}

// Display List
void displayList(const ArrayList &list)
{
    for (int i = 0; i < list.size; i++)
    {
        cout << list.data[i] << " ";
    }

    cout << endl;
}

int main()
{
    ArrayList list;

    int *ptr = list.data;
    int *minPtr = list.data;
    int *maxPtr = list.data;
    int *medianPtr = list.data;
    int *closestPtr = list.data;

    int sum = 0;
    int closestPosition;

    double generalAverage;
    double specialAverage;
    double averageDifference;
    double finalScore;

    // Part A: Insert Values

    insertEnd(list, 18);
    insertEnd(list, 7);
    insertEnd(list, 45);
    insertEnd(list, 11);
    insertEnd(list, 36);
    insertEnd(list, 12);
    insertEnd(list, 21);
    insertEnd(list, 13);
    insertEnd(list, 29);

    cout << "Initial ArrayList: ";
    displayList(list);

    // Part B: Pointer Traversal, Sum, Min, Max

    ptr = list.data;
    minPtr = list.data;
    maxPtr = list.data;

    sum = 0;

    for (int i = 0; i < list.size; i++)
    {
        sum = sum + *ptr;

        if (*ptr < *minPtr)
        {
            minPtr = ptr;
        }

        if (*ptr > *maxPtr)
        {
            maxPtr = ptr;
        }

        ptr++;
    }

    cout << "Minimum Value: " << *minPtr << endl;
    cout << "Maximum Value: " << *maxPtr << endl;
    cout << "Sum: " << sum << endl;

    // Part C: Find Median

    int temp[CAPACITY];

    for (int i = 0; i < list.size; i++)
    {
        temp[i] = list.data[i];
    }

    // Bubble Sort

    for (int i = 0; i < list.size - 1; i++)
    {
        for (int j = 0; j < list.size - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                int swapValue = temp[j];

                temp[j] = temp[j + 1];
                temp[j + 1] = swapValue;
            }
        }
    }

    int medianValue = temp[list.size / 2];

    medianPtr = list.data;

    for (int i = 0; i < list.size; i++)
    {
        if (*medianPtr == medianValue)
        {
            break;
        }

        medianPtr++;
    }

    cout << "Median Value: " << *medianPtr << endl;

    // Part D: Averages and Closest Value

    generalAverage = (double)sum / list.size;

    specialAverage = (*minPtr + *medianPtr + *maxPtr) / 3.0;

    ptr = list.data;
    closestPtr = list.data;

    double smallestDifference = fabs(*ptr - specialAverage);

    for (int i = 0; i < list.size; i++)
    {
        double currentDifference = fabs(*ptr - specialAverage);

        if (currentDifference < smallestDifference)
        {
            smallestDifference = currentDifference;
            closestPtr = ptr;
        }

        ptr++;
    }

    closestPosition = closestPtr - list.data;

    cout << "General Average: " << generalAverage << endl;
    cout << "Special Average: " << specialAverage << endl;
    cout << "Closest Value: " << *closestPtr << endl;
    cout << "Position of Closest Value: " << closestPosition << endl;

    // Part E: Final Calculations

    averageDifference = fabs(generalAverage - specialAverage);

    finalScore = fabs(*closestPtr - generalAverage)
                + fabs(*closestPtr - specialAverage)
                + averageDifference;

    cout << "Difference Between Averages: "
         << averageDifference << endl;

    cout << "Final Score: " << finalScore << endl;

    // Delete Closest Value

    deleteAtPosition(list, closestPosition);

    cout << "ArrayList After Deletion: ";
    displayList(list);

    // Round Special Average and Insert at Beginning

    int roundedSpecialAverage = round(specialAverage);

    insertAtBeginning(list, roundedSpecialAverage);

    cout << "Final ArrayList After Insertion: ";
    displayList(list);

    return 0;
}
