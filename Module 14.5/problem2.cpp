#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> st;
    while (n--)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    int m;
    cin >> m;

    queue<int> qu;
    while (m--)
    {
        int val;
        cin >> val;
        qu.push(val);
    }

    bool isSame = true;
    while (!st.empty() || !qu.empty())
    {
        if ((st.empty() || qu.empty()) || st.top() != qu.front())
        {
            isSame = false;
            break;
        }

        st.pop();
        qu.pop();
    }

    isSame ? cout << "YES" : cout << "NO";

    return 0;
}