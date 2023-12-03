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

    // Static Node
    Node head(10);
    Node a(20);

    head.next = &a;

    // Dynamic Node
    Node *head2 = new Node(10);
    Node *a2 = new Node(20);

    head2->next = a2; // 'a2' itself is a pointer that's why don't need to use '&' sign.

    return 0;
}