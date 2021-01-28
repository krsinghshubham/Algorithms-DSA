// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem162.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // binary search.
        /*
      ans can be either be boundary elements if they are greater than neighbour. 
      else for any mid element ans will lie in the direction bigger than mid element. how ? beacuse we have to return ANY OF THE PEAKS , IF THERE ARE MULTIPLE.
      SO , Greater of peak can lie either on boundary or that side only. 
      time: O(n)
      space: O(1)
        */
        if (nums.size() == 1)
            return 0; // one element, 1st element is ans.
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
                return mid;                // mid==0 && mid==high i dont think can be simultaneously true.
            if (nums[mid] < nums[mid + 1]) // move in increasing direction
                low = mid + 1;
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
