#include <bits/stdc++.h>
using namespace std;

int arr[5] = {1, 2, 3, 4, 5};
int n = size(arr);

/*
    Time Complexity -> Denotes time a programme may take through mathemetical expression

    O(1) -> 10^18
    O(logN) -> 10^18
    O(sqrt(N)) -> 10^14
    O(N) -> 10^7
    O(NlogN) -> 10^5
    O(N^2) -> 10^3
*/

int main()
{

    /* O(1) */
    int a = 5;
    cout << a << " " << endl;

    /* O(logN) */
    int num = 23542;
    while (num <= 0)
    {
        int x = num % 10;
        cout << x << endl;
        num /= 10; // Increasing the rate of closing the loop in each step
    }

    /* O(sqrt(N)) */
    for (int i = 0; i < sqrt(n); i++) // or (i*i < n)
        cout << arr[i];

    /* O(N) */
    for (int i = 0; i < n; i++)
        cout << arr[i];

    /* O(NlogN) */
    for (int i = 0; i < n; i++) // O(N)
    {
        int num = 23542;
        while (num <= 0)  // O(logN)
        {
            int x = num % 10;
            x /= 10;
        }
    }

    /* O(N^2) */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[j];
    }

    return 0;
}
