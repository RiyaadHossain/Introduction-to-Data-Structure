#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*  
        Notes: Implement Balanced binary tree internally
            - Sorted
            - No Duplicates
            - Searching in O(logN)
    */
    set<int> s;
    s.insert(5);
    s.count(2);                   // Check exist or not; Ourtup: 0/1
    cout << *(s.begin()) << endl; // need to de-referrence to access its value
    return 0;
}