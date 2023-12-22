#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string val;
    Node *next;
    Node *prev;

    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertNode(Node *&head, Node *&tail, string val)
{

    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    while (1)
    {
        string val;
        cin >> val;

        if (val == "end")
            break;

        insertNode(head, tail, val);
    }

    int q;
    cin >> q;

    Node *currNode = head;
    while (q--)
    {
        string command;
        cin >> command;

        if (command == "visit")
        {
            string website;
            cin >> website;

            Node *tmp = head;
            while (tmp)
            {
                if (tmp->val == website)
                    break;
                tmp = tmp->next;
            }

            if (tmp)
            {
                cout << tmp->val;
                currNode = tmp;
            }
            else
                cout << "Not Available";
        }

        if (command == "prev")
        {
            if (currNode->prev)
            {
                currNode = currNode->prev;
                cout << currNode->val;
            }
            else
                cout << "Not Available";
        }

        if (command == "next")
        {
            if (currNode->next)
            {
                currNode = currNode->next;
                cout << currNode->val;
            }
            else
                cout << "Not Available";
        }

        cout << endl;
    }

    return 0;
}