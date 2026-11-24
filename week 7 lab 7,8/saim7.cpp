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

// Preorder Traversal: Node, Right, Left (NRL)
void Preorder(BST *root) {
    if (root != NULL) {
        cout << root->data << " > ";
        Preorder(root->right);
        Preorder(root->left);
    }
}

// Postorder Traversal: Right, Left, Node (RLN)
void Postorder(BST *root) {
    if (root != NULL) {
        Postorder(root->right);
        Postorder(root->left);
        cout << root->data << " > ";
    }
}

// Inorder Traversal: Right, Node, Left (RNL)
void Inorder(BST *root) {
    if (root != NULL) {
        Inorder(root->right);
        cout << root->data << " > ";
        Inorder(root->left);
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

    cout << "Preorder (NRL): ";
    Preorder(root);

    cout << "\nPostorder (RLN): ";
    Postorder(root);

    cout << "\nInorder (RNL): ";
    Inorder(root);

    return 0;
}
