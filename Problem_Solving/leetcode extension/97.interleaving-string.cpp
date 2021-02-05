// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem97.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int first=0,second=0;
        int i=0;
        for(i=0;i<s3.length();i++)
        {
            if(first<s1.length() && s3[i]==s1[first])
            { first++;
            continue;
            }
            if(second<s2.length() && s3[i]==s2[second])
            { second++;
            continue;
            }
            else
                break;
            
        }
        if(first==s1.length() && second ==s2.length() && i==s3.length()-1)
            return true;
        return false;
    }
};
// @lc code=end

