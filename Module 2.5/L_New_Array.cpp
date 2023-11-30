#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr1[n];
    int arr2[n];

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    vector<int> vec(arr2, arr2 + n);
    vec.insert(vec.end(), arr1, arr1 + n);

    for (auto it : vec)
        cout << it << " ";

    return 0;
}