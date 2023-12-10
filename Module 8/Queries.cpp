#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertNodeAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void insertNodeAtTail(Node *&head, int val)
{

    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }

    Node *tmp = head;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = newNode;
}

void deleteNode(Node *&head, int pos)
{
    if (!head)
        return;

    if (pos == 0 && head)
    {

        Node *delNode = head;
        head = head->next;
        delete delNode;
        return;
    }

    pos--;
    Node *tmp = head;
    while (pos-- && tmp->next)
        tmp = tmp->next;

    if (!tmp->next)
        return;

    Node *delNode = tmp->next;
    tmp->next = tmp->next->next;
    delete delNode;
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

int main()
{
    Node *head = NULL;

    int q;
    cin >> q;
    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
            insertNodeAtHead(head, v);
        else if (x == 1)
            insertNodeAtTail(head, v);
        else
            deleteNode(head, v);

        printNodes(head);
        cout << endl;
    }

    return 0;
}