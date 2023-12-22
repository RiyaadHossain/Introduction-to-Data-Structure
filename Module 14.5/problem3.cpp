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

    stack<int> auxSt;
    while (!st.empty())
    {
        auxSt.push(st.top());
        st.pop();
    }

    while (!auxSt.empty())
    {
        cout << auxSt.top() << " ";
        auxSt.pop();
    }

    return 0;
}