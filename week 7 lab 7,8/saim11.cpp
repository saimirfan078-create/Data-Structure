
#include <iostream>
#include <queue>
using namespace std;

struct AVL {
    int data;
    AVL *left = NULL;
    AVL *right = NULL;
    int height = 1;
};

// Find the height of a node
int height(AVL *node) {
    if (node == NULL)
        return 0;

    return node->height;
}

// Find the maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Calculate the balance factor
int getBalance(AVL *node) {
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// Perform right rotation
AVL *rightRotate(AVL *y) {
    AVL *x = y->left;
    AVL *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Perform left rotation
AVL *leftRotate(AVL *x) {
    AVL *y = x->right;
    AVL *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Insert a node into AVL Tree
AVL *insert(AVL *node, int value) {
    if (node == NULL) {
        AVL *newNode = new AVL;
        newNode->data = value;
        return newNode;
    }

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Perform level order traversal
void levelOrder(AVL *root) {
    if (root == NULL)
        return;

    queue<AVL *> q;
    q.push(root);

    while (!q.empty()) {
        AVL *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {
    AVL *root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}

