//problem link: https://leetcode.com/problems/max-consecutive-ones/submissions/
// Reference linK: https://www.youtube.com/watch?v=Mo33MjjMlyA&list=PLgUwDviBIf0rBT8io74a95xT-hDFZonNs&index=4&ab_channel=takeUforward
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
Algorithm: Optimal
iterate and keep track of max and count.
* Time: O(N), Space: O(1)
*/

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxm=Integer.MIN_VALUE;
        int cnt=0;
        int n=nums.length;
        if(n==0)
            return 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                cnt++;
            else
            {
                cnt=0;
            }
       maxm=Math.max(cnt,maxm);

        }
        return maxm;
    }
}