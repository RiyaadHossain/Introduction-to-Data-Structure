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

void printNodes(Node *head)
{
    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
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

    Node *curr = head;
    while (curr->next)
    {
        Node *aux = curr->next;
        while (aux)
        {
            cout << aux->val << " ";
            aux = aux->next;
        }
        cout << endl;
        curr = curr->next;
    }

    return 0;
}