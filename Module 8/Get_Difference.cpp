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

    while (1)
    {
        int val;
        cin >> val;

        if (val == -1)
            break;

        insertNode(head, tail, val);
    }

    int max_val = INT_MIN;
    int min_val = INT_MAX;

    Node *tmp = head;
    while (tmp)
    {
        max_val = max(max_val, tmp->val);
        min_val = min(min_val, tmp->val);
        tmp = tmp->next;
    }

    int result = max_val - min_val;
    cout << result;

    return 0;
}