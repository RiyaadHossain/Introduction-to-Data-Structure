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

/* The '&' sign is used to modify head pointer in the main function. Details: if don't use the '&' sign, it only create a copy of the 'head' pointer which will be deleted after executing of the function. Eventually, it'll not make any changes in the 'main' function. */
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
    {
        if (!tmp)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void print_linkedlist(Node *head)
{
    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

void insert_node_at_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_node_at_pos(Node *&head, int pos, int val)
{

    if (pos == 0)
    {
        insert_node_at_head(head, val);
        return;
    }

    Node *newNode = new Node(val);

    pos--; // Access the previsou node of the target node

    Node *tmp = head;
    while (pos--)
    {
        if (!tmp)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        tmp = tmp->next;
    }

    if (!tmp)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    newNode->next = tmp->next;
    tmp->next = newNode;
}

void delete_head(Node *&head)
{

    if (!head)
    {
        cout << "Linked List is empty" << endl;
        return;
    }

    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void delete_node_at_pos(Node *&head, int pos)
{

    if (pos == 0)
    {
        delete_head(head);
        return;
    }

    Node *tmp = head;

    pos--; // Access the previsou node of the target node

    while (pos--)
    {
        if (!tmp)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        tmp = tmp->next;
    }

    if (!tmp)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    Node *delNode = tmp->next;
    tmp->next = tmp->next->next;
    delete delNode;
}

int main()
{

    Node *head = NULL;

    while (1)
    {
        cout << endl;
        cout << "---------------------------------" << endl;
        cout << "Option 1: Insert an Node" << endl;
        cout << "Option 2: Print Linked list" << endl;
        cout << "Option 3: Insert at Position" << endl;
        cout << "Option 4: Insert at head" << endl;
        cout << "Option 5: Delete at Position" << endl;
        cout << "Option 6: Delete Head" << endl;
        cout << "Option 7: Terminate" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;

        cout << "Your option: ";
        int option;
        cin >> option;

        if (option == 1)
        {
            cout << "Enter a value: ";
            int val;
            cin >> val;
            insert_node(head, val);
        }
        else if (option == 2)
        {
            cout << "Your LinkedList: ";
            print_linkedlist(head);
        }
        else if (option == 3)
        {
            cout << "Enter a Postion: ";
            int pos;
            cin >> pos;
            cout << "Enter a value: ";
            int val;
            cin >> val;
            insert_node_at_pos(head, pos, val);
        }
        else if (option == 4)
        {
            cout << "Enter a value: ";
            int val;
            cin >> val;
            insert_node_at_head(head, val);
        }
        else if (option == 5)
        {
            cout << "Enter a postion: ";
            int val;
            cin >> val;
            delete_node_at_pos(head, val);
        }
        else if (option == 6)
        {
            delete_head(head);
        }
        else if (option == 7)
        {
            break;
        }
    }

    return 0;
}