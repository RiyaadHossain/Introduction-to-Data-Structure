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

    Node *listHead1 = NULL;
    Node *listTail1 = NULL;

    Node *listHead2 = NULL;
    Node *listTail2 = NULL;

    int t = 2;
    while (t--)
    {
        while (1)
        {
            int val;
            cin >> val;

            if (val == -1)
                break;

            if (t == 1)
                insertNode(listHead1, listTail1, val);
            else
                insertNode(listHead2, listTail2, val);
        }
    }

    bool isEqual = true;

    Node *tmp1 = listHead1;
    Node *tmp2 = listHead2;

    while (tmp1 || tmp2)
    {

        if ((!tmp1 || !tmp2) || tmp1->val != tmp2->val)
        {
            isEqual = false;
            break;
        }

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    isEqual ? cout << "YES" : cout << "NO";

    return 0;
}