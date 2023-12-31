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

class MyStack
{
public:
    Node *head = NULL;

    void push(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        Node *delNode = head;
        head = head->next;
    }

    int top()
    {
        return head->val;
    }

    bool empty()
    {
        return head == NULL;
    }
};

class MyQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void push(int val)
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

    void pop()
    {
        head = head->next;
        if (!head)
            tail = NULL;
    }

    int front()
    {
        return head->val;
    }

    bool empty()
    {
        return head == NULL;
    }
};

bool sameOrNot2(MyStack st, MyQueue qu)
{
    while (!st.empty() || !qu.empty())
    {
        if (st.empty() || qu.empty() || (st.top() != qu.front()))
            return false;

        st.pop();
        qu.pop();
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    MyStack st;
    MyQueue qu;

    while (n--)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    while (m--)
    {
        int val;
        cin >> val;
        qu.push(val);
    }

    bool result = sameOrNot2(st, qu);

    result ? cout << "YES" : cout << "NO";

    return 0;
}