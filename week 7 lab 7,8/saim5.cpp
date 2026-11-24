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

BST *min() {
    BST *p = root;
    BST *p2 = NULL;

    while (p != NULL) {
        p2 = p;
        p = p->left;
    }

    return p2;
}

BST *max() {
    BST *p = root;
    BST *p2 = NULL;

    while (p != NULL) {
        p2 = p;
        p = p->right;
    }

    return p2;
}

int main() {
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    BST *minimum = min();
    BST *maximum = max();

    if (minimum != NULL) {
        cout << "Minimum value: " << minimum->data << endl;
    }
    else {
        cout << "Tree is empty." << endl;
    }

    if (maximum != NULL) {
        cout << "Maximum value: " << maximum->data << endl;
    }
    else {
        cout << "Tree is empty." << endl;
    }

    return 0;
}
