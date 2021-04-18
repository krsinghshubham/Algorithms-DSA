/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    void addSubSets(int size, vector<int>nums,vector<int>subSet, int index,vector<vector<int>>&ans )
    {
        if(index>size-1) // index cross over
        {
            ans.push_back(subSet);
            return;
        }
        subSet.push_back(nums[index]);
        addSubSets(size,nums, subSet, index+1, ans); // element addedd to subset
        subSet.pop_back();
        addSubSets(size,nums, subSet, index+1, ans); // element not addedd to subset

    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        // no reptitions in chart using recursion, time is O(2^n) but n is less than 10, so it will run
        int index=0;
        int size=nums.size();
        vector<vector<int>>ans;
        vector<int>subSet={};
        addSubSets(size, nums,subSet, index, ans);
        return ans;
    }
};

// @lc code=end

