#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int spaces = 0;
    int spaces2 = n - 2;
    for (int i = 1; i <= n; i++)
    {

        int mid = (n / 2) + 1;

        for (int i = 0; i < spaces; i++)
            cout << " ";

        if (i <= n / 2)
            cout << "\\";
        else if (i > mid)
            cout << "/";

        if (i == mid)
            cout << "X";

        for (int i = 0; i < spaces2; i++)
            cout << " ";

        if (i <= n / 2)
            cout << "/";
        else if (i > mid)
            cout << "\\";

        // Calculating spaces
        if (i < mid)
        {
            spaces++;
            spaces2 -= 2;
        }
        else
        {
            spaces--;
            spaces2 += 2;
        }

        cout << endl;
    }

    return 0;
}