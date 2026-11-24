
#include <iostream> // Provides input and output operations
#include <algorithm> // Provides the max() function
using namespace std; // Allows standard library names without std::

// Defines a node of the AVL tree
struct Node {
    int key;       // Stores the node value
    Node* left;    // Points to the left child
    Node* right;   // Points to the right child
    int height;    // Stores the height of the node

    // Initializes a new node
    Node(int value) {
        key = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Returns the height of a node
int height(Node* n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

// Calculates the balance factor of a node
int getBalance(Node* n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

// Performs a right rotation for LL imbalance
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    // Performs the rotation
    x->right = y;
    y->left = temp;

    // Updates heights after rotation
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    cout << "Right rotation performed." << endl;
    return x;
}

// Performs a left rotation for RR imbalance
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    // Performs the rotation
    y->left = x;
    x->right = temp;

    // Updates heights after rotation
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    cout << "Left rotation performed." << endl;
    return y;
}

// Inserts a key and automatically balances the AVL tree
Node* insert(Node* root, int key) {
    // Performs normal Binary Search Tree insertion
    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        return root; // Does not insert duplicate keys
    }

    // Updates the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Calculates the balance factor
    int balance = getBalance(root);

    // LL case: left subtree of the left child is heavy
    if (balance > 1 && key < root->left->key) {
        cout << "LL case at node " << root->key << endl;
        return rightRotate(root);
    }

    // RR case: right subtree of the right child is heavy
    if (balance < -1 && key > root->right->key) {
        cout << "RR case at node " << root->key << endl;
        return leftRotate(root);
    }

    // LR case: right subtree of the left child is heavy
    if (balance > 1 && key > root->left->key) {
        cout << "LR case at node " << root->key << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL case: left subtree of the right child is heavy
    if (balance < -1 && key < root->right->key) {
        cout << "RL case at node " << root->key << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Returns the unchanged root if it is already balanced
    return root;
}

// Prints the tree in preorder: Root, Left, Right
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Prints the tree in inorder: Left, Root, Right
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Displays the tree sideways to show its structure
void displayTree(Node* root, int space = 0) {
    if (root == NULL) {
        return;
    }

    space += 5;

    // Displays the right subtree first
    displayTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";
    }
    cout << root->key << endl;

    // Displays the left subtree
    displayTree(root->left, space);
}

// Releases allocated memory
void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Inserts the required sequence and displays the results
int main() {
    Node* root = NULL;

    // Uses the exact insertion order given in the question
    int values[] = {110, 10, 20, 120, 100, 40,
                    60, 50, 70, 80, 30, 90};

    int size = sizeof(values) / sizeof(values[0]);

    // Inserts each value into the AVL tree
    for (int i = 0; i < size; i++) {
        cout << "\nInserting " << values[i] << endl;
        root = insert(root, values[i]);
    }

    // Displays the final balanced tree
    cout << "\nFinal AVL Tree (sideways):" << endl;
    displayTree(root);

    // Displays preorder traversal
    cout << "\nPreorder Traversal: ";
    preorder(root);

    // Displays inorder traversal
    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << endl;

    // Frees all allocated nodes
    deleteTree(root);

    return 0; // Ends the program successfully
}

