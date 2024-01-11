#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Usages: when have to store a data against another data (if array is not useful in that particular scenario; like: counting word in a sentence)
    
    map<string, int> mpp;

    // Inserting
    mpp.insert({"riyad", 50});
    mpp["san"] = 23;
    mpp["raki"]++;

    // Searching
    cout << mpp["raki"] << endl;

    // Exist or Not
    mpp.count("riyad") ? cout << "YES" : cout << "No" << endl; // 0 or 1

    return 0;
}