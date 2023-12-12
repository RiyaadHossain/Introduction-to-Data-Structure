#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertNode(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void reverseNodes(Node *head, Node *tail)
{
    Node *left = head;
    Node *right = tail;

    while (left != right && left->next != right)
    {
        swap(left->val, right->val);
        left = left->next;
        right = right->prev;
    }

    // Edge Case: When the list has even number of nodes.
    swap(left->val, right->val);
}

void printNodes(Node *head)
{
    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

void printNodesReverse(Node *tail)
{
    Node *tmp = tail;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }

    cout << endl;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    while (1)
    {
        int val;
        cin >> val;

        if (val == -1)
            break;

        insertNode(head, tail, val);
    }

    reverseNodes(head, tail);
    printNodes(head);

    return 0;
}