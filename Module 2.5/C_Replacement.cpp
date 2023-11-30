#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (int i = 0; i < n; i++)
    {
        if (vec[i] > 0)
            vec[i] = 1;
        else if (vec[i] < 0)
            vec[i] = 2;
    }

    for (auto it : vec)
        cout << it << " ";

    return 0;
}