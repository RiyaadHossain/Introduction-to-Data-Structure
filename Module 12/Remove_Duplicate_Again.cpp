#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> vec;

    while (1)
    {
        int n;
        cin >> n;

        if (n == -1)
            break;

        vec.push_back(n);
    }

    vec.sort();
    vec.unique();

    for (auto &&it : vec)
        cout << it << " ";

    return 0;
}