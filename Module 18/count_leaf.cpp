#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *takeInput()
{
    int val;
    cin >> val;

    Node *root;
    queue<Node *> qu;

    if (val == -1)
    {
        root = NULL;
        return root;
    }

    root = new Node(val);
    qu.push(root);

    while (!qu.empty())
    {
        // 1. Save & Pop front node
        Node *front = qu.front();
        qu.pop();

        // 2. Do something
        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        Node *left = new Node(leftVal);
        Node *right = new Node(rightVal);

        if (leftVal == -1)
            left = NULL;

        if (rightVal == -1)
            right = NULL;

        if (left)
            front->left = left;
        if (right)
            front->right = right;

        // 3. Push children nodes
        if (front->left)
            qu.push(front->left);
        if (front->right)
            qu.push(front->right);
    }

    return root;
}

int countLeafNode(Node *root)
{
    if (!root)
        return 0;

    int leftCount = countLeafNode(root->left);
    int rightCount = countLeafNode(root->right);

    int countNode = (!root->left && !root->right) ? 1 : 0;
    return countNode + leftCount + rightCount;

    /* Another Approach */
    // if (!root)
    //     return 0;
    //
    // if (!root->left && !root->right)
    //     return 1;

    // int leftCount = countLeafNode(root->left);
    // int rightCount = countLeafNode(root->right);

    // return leftCount + rightCount;
}

int main()
{
    Node *root = takeInput();

    int leafNodes = countLeafNode(root);
    cout << "Total leaf Node: " << leafNodes;

    return 0;
}