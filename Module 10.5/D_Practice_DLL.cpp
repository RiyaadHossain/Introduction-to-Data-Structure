#include <bits/stdc++.h>
using namespace std;

/*
    Question:
    You have a doubly linked list which is empty initially.
    You need to take a value Q which refers to queries.
    For each query you will be given X and V.
    You will insert the value V to the Xth index of the doubly linked list and print the list in both left to right and right to left.
    If the index is invalid then print “Invalid”.
*/

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

int getListSize(Node *head)
{
    int cnt = 0;
    Node *tmp = head;
    while (tmp)
    {
        cnt++;
        tmp = tmp->next;
    }

    return cnt;
}

void insertHead(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertTail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (!tail)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertNode(Node *&head, Node *&tail, int pos, int val)
{

    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    pos--;
    Node *tmp = head;
    while (pos--)
        tmp = tmp->next;

    newNode->next = tmp->next;
    newNode->prev = tmp;
    tmp->next->prev = newNode;
    tmp->next = newNode;
}

void printNodes(Node *head)
{
    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void printNodesReverse(Node *tail)
{
    Node *tmp = tail;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    int listSize = 0;

    int q;
    cin >> q;
    while (q--)
    {

        int x, v;
        cin >> x >> v;

        if (x == 0)
            insertHead(head, tail, v);
        else if (x == listSize)
            insertTail(head, tail, v);
        else if (x < listSize)
            insertNode(head, tail, x, v);
        else
            cout << "Invalid";

        if (x <= listSize)
        {
            printNodes(head);
            cout << endl;
            printNodesReverse(tail);
        }

        listSize = getListSize(head);
        cout << endl;
    }

    return 0;
}