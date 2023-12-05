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

void insert_node(Node *&head, int val)
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

void is_sorted(Node *head)
{
    if (!head)
    {
        cout << "LinkedList is Empty" << endl;
        return;
    }

    Node *tmp = head;
    bool is_sorted = true;
    while (tmp->next)
    {
        if (tmp->val > tmp->next->val)
        {
            is_sorted = false;
            break;
        }

        tmp = tmp->next;
    }

    is_sorted ? cout << "YES" : cout << "NO";
}

int main()
{
    Node *head = NULL;

    while (1)
    {
        int val;
        cin >> val;

        if (val == -1)
            break;

        insert_node(head, val);
    }

    is_sorted(head);

    return 0;
}