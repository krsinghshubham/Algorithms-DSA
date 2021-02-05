// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem322.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
   // @lc code=start
   class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if(amount==0)
            return 0;
        int count = 0;
        sort(coins.begin(), coins.end(), [](int a, int b) {
            return a > b;
        });
        int n=coins.size();
        for (auto x : coins)
        {
            if (n>1 && amount >=x)
            {
                count += amount / x;
                amount= amount % x;
            }
            if (n==1)
            {
               if(amount%x==0)
               {
                   count+=amount / x;;
                   return count;
               }
                else
                    return -1;
            }
            n--;
        }
       
        return 0;
    }
};
// @lc code=end
