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

void nodeValues(BinaryTree *root, vector<int> &temp, string side)
{
    if (!root)
        return;

    if (side == "left")
    {
        if (root->left)
            nodeValues(root->left, temp, side);
        else if (root->right)
            nodeValues(root->right, temp, side);
        temp.push_back(root->val);
    }

    if (side == "right")
    {
        temp.push_back(root->val);
        if (root->right)
            nodeValues(root->right, temp, side);
        else if (root->left)
            nodeValues(root->left, temp, side);
    }
}

vector<int> outerTree(BinaryTree *root)
{
    vector<int> leftSide, rightSide;
    nodeValues(root->left, leftSide, "left");
    nodeValues(root->right, rightSide, "right");

    leftSide.push_back(root->val);
    leftSide.insert(leftSide.end(), rightSide.begin(), rightSide.end());

    return leftSide;
}

int main()
{

    BinaryTree *root = takeInputOfBinaryTree();

    vector<int> result = outerTree(root);

    for (int it : result)
        cout << it << " ";

    return 0;
}