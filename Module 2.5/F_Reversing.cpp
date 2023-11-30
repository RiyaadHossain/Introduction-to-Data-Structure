#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (int i = 0; i < n / 2; i++)
        swap(vec[i], vec[n - i - 1]);

    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";

    return 0;
}