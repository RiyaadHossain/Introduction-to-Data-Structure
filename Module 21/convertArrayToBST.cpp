#include <bits/stdc++.h>
using namespace std;

class BinaryTree
{
public:
    int val;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void printBinaryTreeBFS(BinaryTree *root)
{
    queue<BinaryTree *> qu;
    qu.push(root);

    while (!qu.empty())
    {
        BinaryTree *front = qu.front();
        qu.pop();

        cout << front->val << " ";

        if (front->left)
            qu.push(front->left);

        if (front->right)
            qu.push(front->right);
    }
}

BinaryTree* convertArrayToBST(int arr[], int left, int right)
{
    if(left > right)
        return NULL;

    int mid = (left + right) / 2;
    BinaryTree *root = new BinaryTree(arr[mid]);

    root->left = convertArrayToBST(arr, left, mid - 1);
    root->right = convertArrayToBST(arr, mid + 1, right);

    return root;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    for(int it: arr)
        cout << it << " ";

    BinaryTree *root = convertArrayToBST(arr, 0, n-1);

    printBinaryTreeBFS(root);

    return 0;
}