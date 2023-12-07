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

int main()
{

    Node *linked_list1 = NULL;
    Node *linked_list2 = NULL;

    int t = 2;
    while (t--)
    {
        while (1)
        {
            int val;
            cin >> val;

            if (val == -1)
                break;

            if (t)
                insert_node(linked_list1, val);
            else
                insert_node(linked_list2, val);
        }
    }

    list_size(linked_list1) == list_size(linked_list2) ? cout << "YES" : cout << "NO";

    return 0;
}