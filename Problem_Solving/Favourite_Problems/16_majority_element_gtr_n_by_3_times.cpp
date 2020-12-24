//! two approaches, 2nd Optimized approach is below
//problem link: https://leetcode.com/problems/majority-element-ii/
// tutorial linK:https://www.youtube.com/watch?v=yDbkQd9t2ig&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=16&ab_channel=takeUforward
// * learning:  MOORE'S VOTING ALGORITHM
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //done to stop waiting of scanf/printf sync
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
//!BELOW DOWN IS BEST SOLUTION FOR THIS PROBLEM
/*
Algorithm:
USE HASH MAP
*Naive:
* Time: O(n^2), Space: O(1)

*Optimized and best: 
*/
vector<int> majorityElement(vector<int> &nums)
{
    // * Time: O(NLOGN), Space: O(N) // C++ MAP TAKES O(NOGN), SEARCH 1, AND O(N) IS WORST CASE

    //! hash map implementation, time nlogn  space o(n)
    int size = nums.size();
    unordered_map<int, int> m;
    for (auto x : nums)
        m[x]++;
    vector<int> result;
    // for(auto p : m)
    // {
    //     cout<<p.first<<" its "<<p.second<<endl;
    // }
    int cnstrt = floor(size / 3);
    for (auto it : m)
    {
        if (it.second > cnstrt)
        {
            // then majority elemnt is its first.
            result.push_back(it.first);
        }
    } // like in 2nd algo we need not to to a second iteration to check if its really occuring
    // at required no of times or not, because we are storing in map only if its satisfying the required condn.
    return result;
}
vector<int> majorityElement(vector<int> &nums)
{
    //! BOYER MOORE'S VOTING ALGORITHM, time o(N)  space o(1), watching tut every time during revision is recommended.
    //Boyer moore's voting algo.
    //* Time: O(n)+O(n)=O(n), Space: O(1)
    int cr_1 = -1;
    int cr_2 = -1;
    int count_1 = 0;
    int count_2 = 0;
    for (auto x : nums)
    {
        if (x == cr_1)
        {
            count_1++;
        }
        else if (x == cr_2)
        {
            count_2++;
        }
       else if (count_1 == 0)
        {
            cr_1 = x, count_1++;
        }
        else if (count_2 == 0)
        {
            cr_2 = x, count_2++;
        }
        else
        {
            count_1--;
            count_2--;
        }
    }
    // cout<<floor(nums.size()/3)<<endl;
    vector<int> ans;
    count_1 = 0, count_2 = 0;
    for (auto x : nums)
    {
        if (x == cr_1)
            count_1++;
        else if (x == cr_2)
            count_2++;
    }
    if (count_1 > floor(nums.size() / 3))
        ans.push_back(cr_1);
    if (count_2 > floor(nums.size() / 3))
        ans.push_back(cr_2);
    return ans;
}
//! think further for a pattern if majority element is greater than floor of (4, 5... etc) elemnets.
int main()
{
    FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;
    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};

    vector<int> results = majorityElement(nums);
    for (auto x : results)
        cout << x << " ";
    cout << endl;
    vector<int> result = majorityElement(nums);
    for (auto x : result)
        cout << x << " ";
    return 0;
}
