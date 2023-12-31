#include <bits/stdc++.h>
using namespace std;

bool elimination(string &digits)
{
    stack<char> st;
    for (int i = 0; i < digits.size(); i++)
    {
        if (!st.empty() && (digits[i] == '1' && st.top() == '0'))
            st.pop();
        else
            st.push(digits[i]);
    }

    return st.empty();
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string digits;
        cin >> digits;

        bool result = elimination(digits);

        result ? cout << "YES" : cout << "NO";
        cout << endl;
    }

    return 0;
}