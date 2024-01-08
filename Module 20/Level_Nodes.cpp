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

vector<int> levelNodes(BinaryTree *root, int level)
{
    vector<int> result;

    queue<pair<BinaryTree *, int>> qu;
    qu.push({root, 0});

    while (!qu.empty())
    {
        pair<BinaryTree *, int> front = qu.front();
        BinaryTree *node = front.first;
        int currLevel = front.second;
        qu.pop();

        if (currLevel == level)
            result.push_back(node->val);

        if (currLevel > level)
            break;

        if (node->left)
            qu.push({node->left, currLevel + 1});
        if (node->right)
            qu.push({node->right, currLevel + 1});
    }

    return result;
}

int main()
{

    BinaryTree *root = takeInputOfBinaryTree();
    int level;
    cin >> level;

    vector<int> result = levelNodes(root, level);

    if (result.empty())
    {
        cout << "Invalid";
    }
    else
    {
        for (int it : result)
            cout << it << " ";
    }

    return 0;
}