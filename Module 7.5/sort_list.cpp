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

void print_list(Node *head)
{
    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void sort_list(Node *head)
{
    Node *tmp = head;
    while (tmp->next)
    {
        Node *aux = tmp->next;
        while (aux)
        {
            if (tmp->val < aux->val)
                swap(tmp->val, aux->val);

            aux = aux->next;
        }

        tmp = tmp->next;
    }
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

    sort_list(head);
    print_list(head);

    return 0;
}