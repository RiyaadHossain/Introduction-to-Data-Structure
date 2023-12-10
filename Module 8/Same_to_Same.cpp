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
    tail = newNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

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
                insertNode(head, tail, val);
            else
                insertNode(head2, tail2, val);
        }
    }

    Node *tmp = head;
    Node *tmp2 = head2;
    bool isSame = true;
    while (tmp || tmp2)
    {
        if ((!tmp || !tmp2) || tmp->val != tmp2->val)
        {
            isSame = false;
            break;
        }

        tmp = tmp->next;
        tmp2 = tmp2->next;
    }

    isSame ? cout << "YES" : cout << "NO";

    return 0;
}