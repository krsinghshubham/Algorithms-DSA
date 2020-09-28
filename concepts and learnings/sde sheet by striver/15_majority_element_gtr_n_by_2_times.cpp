//! two approaches, 2nd optimised approach is below
//problem link: https://leetcode.com/problems/majority-element/
// tutorial linK:https://www.youtube.com/watch?v=AoX3BPWNnoE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=15&ab_channel=takeUforward
// tut 2: https://www.youtube.com/watch?v=n5QY3x_GNDg&ab_channel=TECHDOSE
// * learning:  MOORE'S VOTING ALGORITHM
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //usually when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
//!BELOW DOWN IS BEST SOLUTION FOR THIS PROBLEM
/*
Algorithm:
USE HASH MAP
*Naive:
* Time: O(n^2), Space: O(1)

*Optimised and best: // moore's voting algo.
* Time: O(n), Space: O(1)
*/
int majrityElement(vector<int> &nums)
{
    // * Time: O(NLOGN), Space: O(N) // C++ MAP TAKES O(NOGN), SEARCH 1, AND O(N) IS WORST CASE

    //! hash map implementaion, time nlogn  space o(n)
    int size = nums.size();
    unordered_map<int, int> m;
    for (auto x : nums)
        m[x]++;
    int count = 0;
    // for(auto p : m)
    // {
    //     cout<<p.first<<" its "<<p.second<<endl;
    // }
    int cnstrt = floor(size / 2);
    for (auto it : m)
    {
        if (it.second > cnstrt)
        {
            // then majority elemnt is its first.
            return it.first;
        }
    }
    return 0;
}
int majorityElement(vector<int> &nums)
{
    //! MOORE'S VOTING ALGORITHM, time o(N)  space o(1)         , theory in notebook
    // * Time: O(N), Space: O(1)

    int count = 0;
    int current_element = NULL;
    for (auto x : nums)
    {
        if (count == 0)
        {
            current_element = x;
            // count++;
        }

        if (x == current_element)
            count++;
        else
        {
            count--;
        }
    }
    return current_element;
}
int main()
{
    FASTIO_TEMPLATE;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majrityElement(nums);
    cout << endl;
    cout << majorityElement(nums);
    return 0;
}
