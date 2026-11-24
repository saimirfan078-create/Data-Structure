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

// Function to find the minimum node in a subtree
BST* findMin(BST *s) {
    while (s != NULL && s->left != NULL) {
        s = s->left;
    }
    return s;
}

// Function to delete a node from BST
BST* deleteNode(BST *s, int key) {
    if (s == NULL) {
        return NULL;
    }

    if (key < s->data) {
        s->left = deleteNode(s->left, key);
    }
    else if (key > s->data) {
        s->right = deleteNode(s->right, key);
    }
    else {
        // Case 1: Node has no child
        if (s->left == NULL && s->right == NULL) {
            delete s;
            return NULL;
        }

        // Case 2: Node has only a right child
        else if (s->left == NULL) {
            BST *temp = s->right;
            delete s;
            return temp;
        }

        // Case 2: Node has only a left child
        else if (s->right == NULL) {
            BST *temp = s->left;
            delete s;
            return temp;
        }

        // Case 3: Node has both children
        else {
            BST *temp = findMin(s->right);
            s->data = temp->data;
            s->right = deleteNode(s->right, temp->data);
        }
    }

    return s;
}

// Function to print BST in Inorder
void Inorder(BST *s) {
    if (s != NULL) {
        Inorder(s->left);
        cout << s->data << " > ";
        Inorder(s->right);
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

    cout << "BST before deletion: ";
    Inorder(root);

    int key;
    cout << "\nEnter value to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "BST after deletion: ";
    Inorder(root);

    return 0;
}
