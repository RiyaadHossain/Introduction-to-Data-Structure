#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(vec.end() == find(vec.begin(), vec.end(), vec[i] + 1)))
            cnt++;
    }

    cout << cnt;

    return 0;
}