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

int sumWithoutLeaf(BinaryTree *root)
{
    if (!root)
        return 0;

    int myVal = (!root->left && !root->right) ? 0 : root->val;

    int left = sumWithoutLeaf(root->left);
    int right = sumWithoutLeaf(root->right);

    return left + right + myVal;
}

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

int main()
{

    BinaryTree *root = takeInputOfBinaryTree();

    int result = sumWithoutLeaf(root);
    cout << result;

    return 0;
}