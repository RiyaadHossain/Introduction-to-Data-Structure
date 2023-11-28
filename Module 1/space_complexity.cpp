#include <bits/stdc++.h>
using namespace std;

/*
    Space Complexity -> denotes the amount of spcae a programme may take
    Calculation -> Same as time complexity

    int arr[n] -> SC O(N)
 */

int main()
{

    int n;
    cin >> n;

    int arr[n] = {0}; // SC -> O(N)

    for (int i = 0; i < n; i++)
    {
        int num = arr[i] + 5; // SC -> O(N); Explanation: Allocate memory in each iteration
        cout << num << " ";
    }

    return 0;
}