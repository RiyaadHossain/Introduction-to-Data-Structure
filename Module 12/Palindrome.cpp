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

    bool isPilandrome = true;

    while (head != tail)
    {
        if (head->val != tail->val)
        {
            isPilandrome = false;
            break;
        }

        if (head->next == tail)
            break;

        head = head->next;
        tail = tail->prev;
    }

    isPilandrome ? cout << "YES" : cout << "NO";

    return 0;
}