//problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// tutorial linK: // self-intituiton, https://www.youtube.com/watch?v=Fm_p9lJ4Z_8&list=PLgUwDviBIf0rBT8io74a95xT-hDFZonNs&index=3&ab_channel=takeUforward
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
use two pointers,one (right) to iterate keep one pointer to keep track of the place where next update will be done (left pointer.)
* Time: O(N), Space: O(1)
*/
 int removeDuplicates(vector<int>& nums)
    {   
        int length=nums.size();
        if(length<=1)
            return length;
        
        int left=0;
        for(int right=1;right<=length;right++) 
        {
            while((right<length) && (nums[right]==nums[left])) // left check is must to avoid address sanitization in LEETCODE
            {
                right++;
            }
            ++left; // cant be done at line 32 as ++left, coz it will not be incremented for TC: nums={2,2}. 
            if(right<length) // check is must to avoid address sanitization in LEETCODE
            nums[left]=nums[right];
        }
        return left;
        /*
        SAME LOGIC BUT SHORT CODE:  // fewer lines and easy to understand.
          int length=nums.size();
        if(length<=1)
            return length;
        
        int left=0;
        for(int right=1;right<length;right++) 
        {
           if(nums[right]!=nums[left])
           {
               left++;
               nums[left]=nums[right];
           }
        }
        */
    }
int main()
{
vector<int>nums={2,2};
int len=removeDuplicates(nums);
for(int i=0;i<len;i++)
cout<<nums[i]<<" ";
}

