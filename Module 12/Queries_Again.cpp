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

int getListSize(Node *head)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
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

void insertTail(Node *&tail, int val)
{
    Node *newNode = new Node(val);

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertNode(Node *head, int pos, int val)
{

    Node *newNode = new Node(val);

    pos--;
    Node *tmp = head;
    while (pos--)
        tmp = tmp->next;

    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    newNode->prev = tmp;
    tmp->next = newNode;
}

void printNodes(Node *head)
{
    cout << "L -> ";

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
    cout << "R -> ";

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

    int q;
    cin >> q;
    while (q--)
    {
        int x, v;
        cin >> x >> v;

        int listSize = getListSize(head);
        bool isInvalid = false;

        if (x == 0)
            insertHead(head, tail, v);
        else if (x == listSize)
            insertTail(tail, v);
        else if (x < listSize)
            insertNode(head, x, v);
        else
            isInvalid = true;

        if (!isInvalid)
        {
            printNodes(head);
            printNodesReverse(tail);
        }
        else
            cout << "Invalid" << endl;
    }

    return 0;
}