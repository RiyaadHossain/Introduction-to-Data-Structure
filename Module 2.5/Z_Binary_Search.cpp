#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    while (q--)
    {
        int target;
        cin >> target;

        if (find(vec.begin(), vec.end(), target) != vec.end())
            cout << "found";
        else
            cout << "not found";

        cout << endl;
    }

    return 0;
}