/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution
{
public:
    bool gcd(string big, string small)
    {
        if (big.length() < small.length())
            return gcd(small, big);
        if (small.empty())
            return true;
        if (big.substr(0, small.size()) != small)
            return false;
        return gcd(big.substr(small.size()), big.substr(small.size()).substr(0,1));
    }
    bool repeatedSubstringPattern(string s)
    {
        // will try to do with gcd.
        string small = to_string(s[0]);
        return gcd(s, small);
    }
};
// @lc code=end
