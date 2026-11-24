#include <iostream>
using namespace std;

struct bst {
    int id;
    bst *left = NULL;
    bst *right = NULL;
};

bst *root = NULL;

void insert(int a) {
    bst *curr = new bst;
    curr->id = a;

    if (root == NULL) {
        root = curr;
    }
    else {
        bst *p = root, *q;

        while (p != NULL) {
            q = p;

            if (curr->id > q->id) {
                p = p->right;
            }
            else {
                p = p->left;
            }
        }

        if (curr->id > q->id) {
            q->right = curr;
        }
        else {
            q->left = curr;
        }
    }
}

void Inorder(struct bst *root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->id << " > ";
        Inorder(root->right);
    }
}

void Preorder(struct bst *root) {
    if (root != NULL) {
        cout << root->id << " > ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct bst *root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->id << " > ";
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

    cout << "Inorder Traversal: ";
    Inorder(root);

    cout << "\nPreorder Traversal: ";
    Preorder(root);

    cout << "\nPostorder Traversal: ";
    Postorder(root);

    return 0;
}
