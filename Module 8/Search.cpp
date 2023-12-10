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

    int t;
    cin >> t;

    while (t--)
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

        int num;
        cin >> num;

        int index = 0;
        Node *tmp = head;
        bool isFound = false;

        while (tmp)
        {
            if (tmp->val == num)
            {
                isFound = true;
                break;
            }

            index++;
            tmp = tmp->next;
        }

        isFound ? cout << index : cout << -1;
        cout << endl;
    }

    return 0;
}