//problem link:https://leetcode.com/problems/two-sum/
// Reference linK:https://www.youtube.com/watch?v=dRUpbt8vHpo&list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_&index=1&ab_channel=takeUforward
// learning: to find indices of array whose sum is equals to target.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //done to stop waiting of scanf/printf sync
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
* Approach 1: Brute Force
The brute force approach is simple. 
Loop through each element xx and find if there is another value that equals to target - xtarget−x.
*Approach 2: One-pass Hash Table 
Note: this particularly guarantees that only one such pair exists. 
we need to keep the indices also so will use map
in one-pass. While we iterate and inserting elements into the table, we also look back to check if current element's complement already exists in the table. 
If it exists, we have found a solution and return immediately
Time complexity : O(n) We traverse the list containing nn elements only once. Each look up in the table costs only O(1)O(1) time.
Space complexity : O(n) The extra space required depends on the number of items stored in the hash table, which stores at most nn elements.
*/
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        // vector<int> nums = {2, 6, 5, 8, 15};
        if (mpp.find(target - nums[i]) != mpp.end()) // means its compliment is present
        {
            ans.push_back(i);
            ans.push_back(mpp[target - nums[i]]); // * because key will return value which in this case is index.
            return ans;
        }
        // means element not present in index.
        mpp[nums[i]] = i; // assinging the index to the elemnts of the array
        // cout<<nums[i]<<" "<<mpp[nums[i]]<<endl;
    }
    return ans;
}
int main()
{
    FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;
    vector<int> nums = {2, 6, 5, 8, 15};

    int target = 14;
    vector<int> res = twoSum(nums, target);
    for (auto x : res)
        cout << x << " ";
    return 0;
}