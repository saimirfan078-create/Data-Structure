#include <iostream>
using namespace std;

struct BST {
    int marks;
    BST *left = NULL;
    BST *right = NULL;
};

BST *root = NULL;

void insertroot(BST *curr)
{
    root = curr;
}

void recursive_insert(BST *root, BST *curr)
{
    if (root == NULL)
    {
        insertroot(curr);
    }
    else
    {
        if (root->marks < curr->marks)
        {
            if (root->right == NULL)
            {
                root->right = curr;
            }
            else
            {
                recursive_insert(root->right, curr);
            }
        }
        else
        {
            if (root->left == NULL)
            {
                root->left = curr;
            }
            else
            {
                recursive_insert(root->left, curr);
            }
        }
    }
}

void Inorder(BST *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->marks << " > ";
        Inorder(root->right);
    }
}

int main()
{
    int n, marks;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks: ";
        cin >> marks;

        BST *curr = new BST;
        curr->marks = marks;

        recursive_insert(root, curr);
    }

    cout << "\nInorder Traversal: ";
    Inorder(root);

    return 0;
}
