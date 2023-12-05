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

int linkedlist_size(Node *head)
{
    int size = 0;
    Node *tmp = head;
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }

    return size;
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

void print_linkedlist(Node *head)
{
    cout << "Your LinkedList: ";

    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

void print_size(Node *head)
{

    int size = 0;
    Node *tmp = head;
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }

    cout << "Your LinkedList's Size: " << size << endl;
}

void has_duplicate_value(Node *head)
{
    if (!head)
    {
        cout << "NO" << endl;
        return;
    }

    bool has_duplicate = false;

    Node *tmp = head;
    while (tmp->next)
    {
        int currVal = tmp->val;
        Node *currNode = tmp->next;
        while (currNode)
        {
            if (currVal == currNode->val)
            {
                has_duplicate = true;
                break;
            }
            currNode = currNode->next;
        }

        if (has_duplicate)
            break;

        tmp = tmp->next;
    }

    has_duplicate ? cout << "YES" : cout << "NO";
    cout << endl;
}

void print_middle(Node *head)
{

    if (!head)
    {
        cout << "Linkedlist is empty" << endl;
        return;
    }

    cout << "Middle Elements: ";
    int size = linkedlist_size(head);

    int i = 1;
    Node *tmp = head;
    while (i <= (size / 2) + 1)
    {
        if (size % 2 == 0)
        {
            if (i == size / 2)
            {
                cout << tmp->val << " " << tmp->next->val << endl;
                break;
            }
        }
        else
        {
            if (i == (size / 2) + 1)
            {
                cout << tmp->val << endl;
                break;
            }
        }

        i++;
        tmp = tmp->next;
    }
}

int main()
{
    Node *head = NULL;

    cout << "Enter linkedlist values: ";
    while (1)
    {
        int val;
        cin >> val;

        if (val == -1)
            break;

        insert_node(head, val);
    }
    print_linkedlist(head);
    // print_size(head);
    // has_duplicate_value(head);
    // print_middle(head);

    return 0;
}