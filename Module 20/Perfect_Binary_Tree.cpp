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

int helper(BinaryTree *root, bool &isPerfectBT)
{
    if (!root)
        return 0;

    int left = helper(root->left, isPerfectBT);
    int right = helper(root->right, isPerfectBT);

    if (left != right)
        isPerfectBT = false;

    return left + right + 1;
}

bool perfectBinaryTree(BinaryTree *root)
{
    bool isPerfectBT = true;
    helper(root, isPerfectBT);
    return isPerfectBT;
}

int main()
{

    BinaryTree *root = takeInputOfBinaryTree();

    bool result = perfectBinaryTree(root);

    result ? cout << "YES" : cout << "NO";

    return 0;
}