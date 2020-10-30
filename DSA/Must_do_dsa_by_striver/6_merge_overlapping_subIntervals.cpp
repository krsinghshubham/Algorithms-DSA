//problem link: https://leetcode.com/problems/merge-intervals/
// tutorial linK: https://youtu.be/2JzRBPFYbKE?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    vector<int> temp;
    if (intervals.size() == 0)
        return result; // if empty array then return empty structure.

    temp = intervals[0]; //we will also compare elements of intervals to its own.
    for (auto x : intervals)
    { // intitaly temp contains the 1st set itself
        if (x[0] <= temp[1])
            temp[1] = max(x[1], temp[1]); // keep updating right index of temp untill right index is in its current range
        else                              // means current x is not in range of previous, so store the temp and mark temp as current x;
        {
            result.push_back(temp);
            temp = x;
        }
        //! keep note that for last element temp wont be doing anything, becuase nothing in right to compare...
        //!so push back what ever remains in temp(the last pair probably into final result)
    }
    result.push_back(temp);

    return result;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.tie(NULL); //usuall when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {8, 9}, {9, 11}, {15, 18}, {2, 4}};
    vector<vector<int>> result = merge(intervals);
    for (auto x : intervals)
    {
        cout << "(";
        for (auto k : x)
            cout << k << " ";
        cout << ")";
    }
    cout << "\nfinal pair:\n";
    for (auto x : result)
    {
        cout << "(";
        for (auto k : x)
            cout << k << " ";
        cout << ")";
    }
    return 0;
}
