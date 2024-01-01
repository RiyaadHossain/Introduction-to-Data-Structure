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

/* Another Approach */
int max_height = INT_MIN;
void maxHeight(Node *root, int height)
{
    if (!root)
        return;

    height++;
    maxHeight(root->left, height);
    maxHeight(root->right, height);

    max_height = max(max_height, height);
    height--;
}

/* Better Approach */
int maxHeightBetter(Node *root)
{
    if (!root)
        return 0;

    int leftHeight = maxHeightBetter(root->left);
    int rightHeight = maxHeightBetter(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node *root = takeInput();

    maxHeight(root, 0);

    cout << "Max height: " << maxHeightBetter(root);

    return 0;
}