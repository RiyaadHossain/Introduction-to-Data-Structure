#include <bits/stdc++.h>
using namespace std;

bool sameOrNot(stack<int> &st, queue<int> &qu)
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

    stack<int> st;
    queue<int> qu;

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

    bool result = sameOrNot(st, qu);

    result ? cout << "YES" : cout << "NO";

    return 0;
}