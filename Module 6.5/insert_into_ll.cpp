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

void print_nodes(Node *head)
{
    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

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

void insert_at_pos(Node *&head, int pos, int val)
{
    Node *newNode = new Node(val);

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        print_nodes(head);
        return;
    }

    pos--;
    Node *tmp = head;
    while (pos--)
    {
        tmp = tmp->next;
        if (!tmp)
        {
            cout << "Invalid" << endl;
            return;
        }
    }

    newNode->next = tmp->next;
    tmp->next = newNode;

    print_nodes(head);
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

    int q;
    cin >> q;
    while (q--)
    {
        int pos, val;
        cin >> pos >> val;

        insert_at_pos(head, pos, val);
    }

    return 0;
}