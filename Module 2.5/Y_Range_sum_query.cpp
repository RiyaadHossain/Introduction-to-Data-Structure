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
        int left, right;
        cin >> left >> right;

        long long sum = 0;
        for (int i = left - 1; i < right; i++)
            sum += vec[i];

        cout << sum << endl;
    }

    return 0;
}