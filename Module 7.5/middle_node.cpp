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

int list_size(Node *head)
{
    int count = 0;
    Node *tmp = head;

    while (tmp)
    {
        count++;
        tmp = tmp->next;
    }

    return count;
}

void print_middle_node(Node *head)
{
    int size = list_size(head);

    // Edge Case
    if (size == 1)
    {
        cout << head->val;
        return;
    }

    bool isEven = size % 2 == 0;
    size /= 2;

    size--;
    Node *tmp = head;
    while (size--)
        tmp = tmp->next;

    if (isEven)
        cout << tmp->val << " " << tmp->next->val;
    else
        cout << tmp->next->val;
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

    print_middle_node(head);

    return 0;
}