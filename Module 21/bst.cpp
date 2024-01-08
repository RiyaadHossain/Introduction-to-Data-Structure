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

bool bst(BinaryTree *root, int target)
{
    if (!root)
        return false;

    if (root->val == target)
        return true;

    if (root->val > target)
        return bst(root->left, target);

    return bst(root->right, target);
}

int main()
{
    BinaryTree *root = takeInputOfBinaryTree();

    int target;
    cin >> target;

    bool isFound = bst(root, target);

    isFound ? cout << "Found" : cout << "Not Found";

    return 0;
}