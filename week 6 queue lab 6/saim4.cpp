#include <iostream>
#include <cstdlib> // for exit()
using namespace std;

#define SIZE 20

class dequeue {
    int a[SIZE], f, r;
public:
    dequeue();
    void insert_at_beg(int);
    void insert_at_end(int);
    void delete_fr_front();
    void delete_fr_rear();
    void show();
};

dequeue::dequeue() {
    f = -1;
    r = -1;
}

void dequeue::insert_at_end(int i) {
    if (r >= SIZE - 1) {
        cout << "\nInsertion is not possible, overflow!!!!";
    } else {
        if (f == -1) {
            f = 0;
            r = 0;
        } else {
            r = r + 1;
        }
        a[r] = i;
        cout << "\nInserted item is: " << a[r];
    }
}

void dequeue::insert_at_beg(int i) {
    if (f == -1) {
        f = 0;
        a[++r] = i;
        cout << "\nInserted element is: " << i;
    } else if (f != 0) {
        a[--f] = i;
        cout << "\nInserted element is: " << i;
    } else {
        cout << "\nInsertion is not possible, overflow!!!";
    }
}

void dequeue::delete_fr_front() {
    if (f == -1) {
        cout << "\nDeletion is not possible::dequeue is empty";
        return;
    } else {
        cout << "\nThe deleted element is: " << a[f];
        if (f == r) {
            f = r = -1;
            return;
        } else {
            f = f + 1;
        }
    }
}

void dequeue::delete_fr_rear() {
    if (f == -1) {
        cout << "\nDeletion is not possible::dequeue is empty";
        return;
    } else {
        cout << "\nThe deleted element is: " << a[r];
        if (f == r) {
            f = r = -1;
        } else {
            r = r - 1;
        }
    }
}

void dequeue::show() {
    if (f == -1) {
        cout << "\nDequeue is empty";
    } else {
        cout << "\nDequeue elements: ";
        for (int i = f; i <= r; i++) {
            cout << a[i] << " ";
        }
    }
}

int main() {
    int c, i;
    dequeue d;
    
    do { // perform switch operation
        cout << "\n\n1. Insert at beginning";
        cout << "\n2. Insert at end";
        cout << "\n3. Show";
        cout << "\n4. Deletion from front";
        cout << "\n5. Deletion from rear";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> c;
        
        switch (c) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> i;
                d.insert_at_beg(i);
                break;
            case 2:
                cout << "Enter the element to be inserted: ";
                cin >> i;
                d.insert_at_end(i);
                break;
            case 3:
                d.show();
                break;
            case 4:
                d.delete_fr_front();
                break;
            case 5:
                d.delete_fr_rear();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Invalid choice";
                break;
        }
    } while (c != 6); // Loop terminates when user selects option 6

    return 0;
}
