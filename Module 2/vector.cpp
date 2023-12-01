#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n); // vec(n, 0) -> every element will take 0 as their value

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (auto i = vec.begin(); i < vec.end(); i++)
        cout << *i << " ";

    cout << endl;

    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    vec.resize(4); // if new element is added, it'll take gerbage value or user defined value at the second param.
    vec.clear();   // Clears the vector elements. Do not delete the memory, only clear the value. vec.size will be 0.
    cout << "Empty: " << vec.empty() << endl;

    vec.assign(3, 3); // 1st Param: postion, 2nd Param: value to be assigned (Note: resize the vector & all elements will take the user defined value)
    vec.insert(vec.begin() + 1, 5);
    vec.erase(vec.begin() + 1);

    vec.push_back(2);

    replace(vec.begin(), vec.end(), 2, 5);
    for (auto it : vec)
        cout << it << " ";

    cout << endl;

    vector<int>::iterator it = find(vec.begin(), vec.end(), 5);
    it != vec.end() ? cout << "Found" : cout << "Not Found";

    return 0;
}
