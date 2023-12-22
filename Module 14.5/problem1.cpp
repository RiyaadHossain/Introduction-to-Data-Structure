#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
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

    void pop()
    {
        sz--;
        Node *delNode = tail;
        tail = tail->prev;

        if (tail)
            tail->next = NULL;
        else
            head = NULL;

        delete delNode;
    }

    int top()
    {
        return tail->val;
    }

    bool empty()
    {
        return tail == NULL;
    }

    int size()
    {
        return sz;
    }
};

int main()
{
    int n;
    cin >> n;
    MyStack st1;
    while (n--)
    {
        int val;
        cin >> val;
        st1.push(val);
    }

    int m;
    cin >> m;
    MyStack st2;
    while (m--)
    {
        int val;
        cin >> val;
        st2.push(val);
    }

    bool isSame = true;
    while (!st1.empty() || !st2.empty())
    {
        if ((st1.empty() || st2.empty()) || st1.top() != st2.top())
        {
            isSame = false;
            break;
        }

        st1.pop();
        st2.pop();
    }

    isSame ? cout << "YES" : cout << "NO";

    return 0;
}