#include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
public:
    int val;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

BinaryTree *takeInputOfBinaryTree()
{
    int val;
    cin >> val;

    BinaryTree *root = new BinaryTree(val);
    queue<BinaryTree *> qu;
    qu.push(root);

    while (!qu.empty())
    {
        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        BinaryTree *front = qu.front();
        qu.pop();

        BinaryTree *left = leftVal != -1 ? new BinaryTree(leftVal) : NULL;
        BinaryTree *right = rightVal != -1 ? new BinaryTree(rightVal) : NULL;

        if (left)
        {
            front->left = left;
            qu.push(left);
        }
        if (right)
        {
            front->right = right;
            qu.push(right);
        }
    }

    return root;
}

void printBinaryTreeBFS(BinaryTree *root)
{
    queue<BinaryTree *> qu;
    qu.push(root);

    while (!qu.empty())
    {
        BinaryTree *front = qu.front();
        qu.pop();

        cout << front->val << " ";

        if (front->left)
            qu.push(front->left);

        if (front->right)
            qu.push(front->right);
    }
}

BinaryTree *insertInBST(BinaryTree *root, int val)
{
    if (!root)
        return new BinaryTree(val);

    if (root->val > val)
        root->left = insertInBST(root->left, val);
    else
        root->right = insertInBST(root->right, val);

    return root;
}

int main()
{
    BinaryTree *root = takeInputOfBinaryTree();

    int val;
    cin >> val;

    insertInBST(root, val);
    printBinaryTreeBFS(root);

    return 0;
}