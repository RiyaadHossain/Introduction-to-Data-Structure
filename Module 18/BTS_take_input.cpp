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

void levelOrder(Node *root)
{

    if (!root)
        return;

    queue<Node *> qu;

    qu.push(root);

    while (!qu.empty())
    {
        // 1. Save & Pop front node
        Node *front = qu.front();
        qu.pop();

        // 2. Do something
        cout << front->val << " ";

        // 3. Push children nodes
        if (front->left)
            qu.push(front->left);
        if (front->right)
            qu.push(front->right);
    }
}

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

int main()
{
    Node *root = takeInput();

    levelOrder(root);

    return 0;
}