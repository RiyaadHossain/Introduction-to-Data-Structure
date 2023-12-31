#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    queue<string> counter;
    while (t--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 0)
        {
            string person;
            cin >> person;
            counter.push(person);
            continue;
        }

        if (!counter.empty())
        {
            cout << counter.front() << endl;
            counter.pop();
        }
        else
            cout << "Invalid" << endl;
    }

    return 0;
}