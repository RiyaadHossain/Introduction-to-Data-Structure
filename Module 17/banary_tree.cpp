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

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
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

    /*  Traversing */
    // 1. Pre-Order -> root, left, right
    cout << "Pre-Order: ";
    preOrder(root);
    cout << endl;

    // 2. Post-Order -> left, right, root
    cout << "Post-Order: ";
    postOrder(root);
    cout << endl;

    // 3. In-Order -> left, root, right
    cout << "In-Order: ";
    inOrder(root);
    cout << endl;

    return 0;
}