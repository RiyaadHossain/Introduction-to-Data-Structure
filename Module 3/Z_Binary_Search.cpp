#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return true;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main()
{
    int n, q;
    cin >> n >> q;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n); // TC -> O(NlogN)

    while (q--) // TC -> O(Q)
    {
        int target;
        cin >> target;

        bool found = binarySearch(arr, n, target); // TC -> O(logN)
        found ? cout << "found" : cout << "not found";
        cout << endl;
    }

    /* Time Complexity Calculation */
    // O(NlogN) + O(QlogN) --> O(NlogN)

    return 0;
}