
#include <iostream>
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

// Right rotation for LL case
AVL *rightRotate(AVL *y) {
    AVL *x = y->left;
    AVL *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left rotation for RR case
AVL *leftRotate(AVL *x) {
    AVL *y = x->right;
    AVL *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Insert a node and balance the AVL tree
AVL *insert(AVL *node, int value) {
    // Perform normal BST insertion
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

    // Update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Calculate the balance factor
    int balance = getBalance(node);

    // Case 1: LL Rotation
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Case 2: RR Rotation
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Case 3: LR Rotation
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: RL Rotation
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Display the tree using inorder traversal
void inorder(AVL *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Display the tree using preorder traversal
void preorder(AVL *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    AVL *root = NULL;
    int choice, value;

    do {
        cout << "\n\n1. Insert (LL Rotation Test)";
        cout << "\n2. Insert (RR Rotation Test)";
        cout << "\n3. Insert (LR Rotation Test)";
        cout << "\n4. Insert (RL Rotation Test)";
        cout << "\n5. Display Inorder";
        cout << "\n6. Display Preorder";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = insert(root, 30);
                root = insert(root, 20);
                root = insert(root, 10);
                cout << "LL rotation test completed.";
                break;

            case 2:
                root = insert(root, 10);
                root = insert(root, 20);
                root = insert(root, 30);
                cout << "RR rotation test completed.";
                break;

            case 3:
                root = insert(root, 30);
                root = insert(root, 10);
                root = insert(root, 20);
                cout << "LR rotation test completed.";
                break;

            case 4:
                root = insert(root, 10);
                root = insert(root, 30);
                root = insert(root, 20);
                cout << "RL rotation test completed.";
                break;

            case 5:
                cout << "Inorder: ";
                inorder(root);
                break;

            case 6:
                cout << "Preorder: ";
                preorder(root);
                break;

            case 7:
                cout << "Program ended.";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 7);

    return 0;
}

