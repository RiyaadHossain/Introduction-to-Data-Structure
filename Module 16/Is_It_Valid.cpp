#include <bits/stdc++.h>
using namespace std;

bool isItValid(string &digits)
{
    stack<char> st;
    for (int i = 0; i < digits.size(); i++)
    {
        if (st.empty())
            st.push(digits[i]);
        else if (digits[i] == '0' && st.top() == '1')
            st.pop();
        else if (digits[i] == '1' && st.top() == '0')
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

        bool result = isItValid(digits);

        result ? cout << "YES" : cout << "NO";
        cout << endl;
    }

    return 0;
}