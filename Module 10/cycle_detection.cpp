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

int main()
{

    Node *head = NULL;

    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);

    // Connection
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;

    bool cycleDetected = false;
    Node *fast = head;
    Node *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            cycleDetected = true;
            break;
        }
    }

    cycleDetected ? cout << "Cycle Detected" : cout << "Cycle Not Detected";
    cout << endl;

    return 0;
}