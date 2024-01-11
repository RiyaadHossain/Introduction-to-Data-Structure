#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class Cmp
{
public:
    /*
        Notes: Internally - complete binary tree; height - O(logN)
         - For priority queue we have to pass a compare class but for sort function we pass a compare function.
         - Have to use operator function which returns boolean
         - Return true if we need to swap between a and b. Like: in our case we want the priority queue to be       sorted in descenting order that's why the condition is a.marks < b.marks
    */

    bool operator()(Student a, Student b)
    {
        if (a.marks < b.marks)
            return true;
        else if (a.marks > b.marks)
            return false;
        else
            return a.roll > b.roll;
    }
};

int main()
{
    /*
        # Priority queue with in-built data type

        priority_queue<int> qu; // -> max value at top
        priority_queue<int, vector<int>, greater<int>> qu; // -> min value at top

        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            qu.push(val);
        }

        while (!qu.empty())
        {
            cout << qu.top() << " ";
            qu.pop();
        }
    */

    /*
        # Priority queue with user defined data type
    */
    priority_queue<Student, vector<Student>, Cmp> qu;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student newStudent(name, roll, marks);
        qu.push(newStudent);
    }

    while (!qu.empty())
    {
        Student student = qu.top();
        cout << student.name << " " << student.roll << " " << student.marks << endl;
        qu.pop();
    }

    return 0;
}