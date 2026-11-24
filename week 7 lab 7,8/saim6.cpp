#include <iostream>
using namespace std;

struct BST {
    int data;
    BST *left = NULL;
    BST *right = NULL;
};

BST *root = NULL;
int count = 0;
int add = 0;

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

void sum(BST *s) {
    if (s != NULL) {
        count = count + 1;
        add = add + s->data;

        sum(s->left);
        sum(s->right);
    }
}

int main() {
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    sum(root);

    cout << "Total nodes: " << count << endl;
    cout << "Sum of all values: " << add << endl;

    return 0;
}
