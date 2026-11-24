#include <iostream>
using namespace std;

struct BST {
    int data;
    BST *left = NULL;
    BST *right = NULL;
};

BST *root = NULL;

void insert(int value) {
    BST *curr = new BST;
    curr->data = value;

    if (root == NULL) {
        root = curr;
    }
    else {
        BST *p = root;
        BST *q = NULL;

        while (p != NULL) {
            q = p;

            if (value > p->data) {
                p = p->right;
            }
            else {
                p = p->left;
            }
        }

        if (value > q->data) {
            q->right = curr;
        }
        else {
            q->left = curr;
        }
    }
}

BST *search(int key) {
    BST *p = root;

    while (p != NULL && p->data != key) {
        if (key > p->data) {
            p = p->right;
        }
        else {
            p = p->left;
        }
    }

    return p;
}

int main() {
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    int key;

    cout << "Enter value to search: ";
    cin >> key;

    BST *result = search(key);

    if (result != NULL) {
        cout << "Value found: " << result->data;
    }
    else {
        cout << "Value not found";
    }

    return 0;
}
