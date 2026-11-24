#include <iostream>
using namespace std;

struct BST {
    int data;
    BST *left = NULL;
    BST *right = NULL;
};

BST *root = NULL;

// Function to insert a node into BST
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

// Function to print and count leaf nodes
int leaf(BST *s) {
    if (s == NULL) {
        return 0;
    }

    // Check whether the node is a leaf node
    if (s->left == NULL && s->right == NULL) {
        cout << s->data << " > ";
        return 1;
    }

    // Count leaf nodes in left and right subtrees
    return leaf(s->left) + leaf(s->right);
}

int main() {
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    cout << "Leaf Nodes: ";
    int count = leaf(root);

    cout << "\nTotal Leaf Nodes: " << count << endl;

    return 0;
}
