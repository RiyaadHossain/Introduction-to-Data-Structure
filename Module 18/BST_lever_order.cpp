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

int main()
{
    Node *root = new Node(10);
    Node *node1 = new Node(20);
    Node *node2 = new Node(30);
    Node *node3 = new Node(40);
    Node *node4 = new Node(50);
    Node *node5 = new Node(60);
    Node *node6 = new Node(70);
    Node *node7 = new Node(80);
    Node *node8 = new Node(90);
    Node *node9 = new Node(100);
    Node *node10 = new Node(1000);

    // Connections
    root->left = node1;
    root->right = node2;

    node1->left = node3;
    node1->right = node4;

    node3->right = node5;

    node2->left = node6;
    node2->right = node7;

    node6->left = node8;

    node7->left = node9;
    node7->right = node10;

    levelOrder(root);

    return 0;
}