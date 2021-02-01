/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
/*
        Algorithm: 
            make a map to store characters and count of t. 
            track count, whenever countSize==tSize we found an eligble window. 
            now when map contains counts of all as 0, means we found all the chars in window. 
            after discovering we will move left pointer un till we make the window ineligible again by moving next of an required character(decrease char frequency and count by 1),
            from there we will look for another eligible window, and in the mean time if we encounter a character again we will decrease the count in map in negative indicating it has occurred more than once.
*/
// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map(char,int)mp;
        for(auto x: t)
        {
            mp[x]++;
        }
        // a=1, b=1, c=1
        int count=0;
        
    }
};
// @lc code=end
