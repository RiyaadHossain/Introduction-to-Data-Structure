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

void insertAtHead(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    // Edge Case
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

void insertAtTail(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);

    // Edge Case
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

void insertAtPos(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    pos--;

    Node *tmp = head;
    while (pos--)
        tmp = tmp->next;

    newNode->next = tmp->next;
    newNode->prev = tmp;
    tmp->next = newNode;
    newNode->next->prev = newNode;
}

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

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);

    // Connection
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    Node *tail = c;

    int listSize = getListSize(head);

    int pos, val;
    cin >> pos >> val;

    if (pos > listSize)
        cout << "Invalid Position" << endl;
    else if (pos == 0)
        insertAtHead(head, tail, val);
    else if (pos == listSize)
        insertAtTail(head, tail, val);
    else
        insertAtPos(head, pos, val);

    printNodes(head);
    printNodesReverse(tail);

    return 0;
}