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

void reverse_print(Node *head)
{
    if (!head)
        return;

    int val = head->val;
    reverse_print(head->next);
    cout << val << " ";
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

    reverse_print(head);

    return 0;
}