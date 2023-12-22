#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int> qu;
    while (n--)
    {
        int val;
        cin >> val;
        qu.push(val);
    }

    stack<int> st;
    while (!qu.empty())
    {
        st.push(qu.front());
        qu.pop();
    }

    queue<int> result;
    while (!st.empty())
    {
        result.push(st.top());
        st.pop();
    }

    while (!result.empty())
    {
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}