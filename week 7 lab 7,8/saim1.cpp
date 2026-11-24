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

    return 0;
}
