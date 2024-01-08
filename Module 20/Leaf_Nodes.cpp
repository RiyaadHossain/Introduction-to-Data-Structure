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

void helper(BinaryTree *root, vector<int> &result)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        result.push_back(root->val);

    helper(root->right, result);
    helper(root->left, result);
}

vector<int> reverseLeavesValue(BinaryTree *root)
{
    vector<int> result;

    helper(root, result);
    sort(result.begin(), result.end(), greater<int>());
    return result;
}

int main()
{

    BinaryTree *root = takeInputOfBinaryTree();

    vector<int> result = reverseLeavesValue(root);

    for (int it : result)
        cout << it << " ";

    return 0;
}