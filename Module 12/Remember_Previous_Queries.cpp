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

void deleteHead(Node *&head, Node *&tail)
{
    if (!head)
        return;

    if (head == tail)
    {
        Node *delNode = head;
        head = NULL;
        tail = NULL;
        delete delNode;
        return;
    }

    if (head->next == tail) // If the list has only two nodes
        tail->prev = NULL;

    Node *delNode = head;
    head = head->next;
    head->prev = NULL;

    delete delNode;
}

void deleteTail(Node *&head, Node *&tail)
{
    if (!tail)
        return;

    if (head == tail)
    {
        Node *delNode = tail;
        head = NULL;
        tail = NULL;
        delete delNode;
        return;
    }

    if (tail->prev == head) // If the list has only two nodes
        head->next = NULL;

    Node *delNode = tail;
    tail = tail->prev;
    tail->next = NULL;

    delete delNode;
}

void deleteNode(Node *&head, Node *&tail, int pos, int listSize)
{

    if (pos == 0)
    {
        deleteHead(head, tail);
        return;
    }

    if (pos == listSize - 1)
    {
        deleteTail(head, tail);
        return;
    }

    pos--;
    Node *tmp = head;
    while (pos > 0)
    {
        if (!tmp)
            return;
        pos--;
        tmp = tmp->next;
    }

    Node *delNode = tmp->next;
    tmp->next = delNode->next;
    tmp->next->prev = tmp;
    delete delNode;
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
        else if (x == 1)
            insertTail(head, tail, v);
        else if (v < listSize)
            deleteNode(head, tail, v, listSize);

        printNodes(head);
        printNodesReverse(tail);
    }

    return 0;
}