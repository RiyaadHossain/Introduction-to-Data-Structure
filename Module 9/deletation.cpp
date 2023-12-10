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

void deleteHead(Node *&head)
{
    if (!head)
        return;

    Node *delNode = head;
    head = head->next;
    head->prev = NULL;
    delete delNode;
}

void deleteTail(Node *&tail)
{
    if (!tail)
        return;

    Node *delNode = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete delNode;
}

void deleteAtPos(Node *head, int pos)
{
    pos--;

    Node *tmp = head;
    while (pos--)
        tmp = tmp->next;

    Node *delNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete delNode;
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

    int pos;
    cin >> pos;

    if (pos >= listSize)
    {
        cout << "Invalid" << endl;
    }
    else if (pos == 0)
        deleteHead(head);
    else if (pos == listSize - 1)
        deleteTail(tail);
    else
        deleteAtPos(head, pos);

    printNodes(head);
    printNodesReverse(tail);

    return 0;
}