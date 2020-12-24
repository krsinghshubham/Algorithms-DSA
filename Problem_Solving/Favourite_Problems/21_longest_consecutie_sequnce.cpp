//problem link:https://leetcode.com/problems/longest-consecutive-sequence/solution/
// tutorial linK: myself
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //done to stop waiting of scanf/printf sync
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
                       /*
Algorithm:
naive:
for each element of array if count length uptill its successor is prensent in it....
update longest sum till for each num.
boolean arrayContains(int[] arr, int num)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}
int longestConsecutive(int[] nums)
{
    int longestStreak = 0;
    for (int num : nums)
    {
        int currentNum = num;
        int currentStreak = 1;
        while (arrayContains(nums, currentNum + 1))
        {
            currentNum += 1;
            currentStreak += 1;
        }
        longestStreak = Math.max(longestStreak, currentStreak);
    }
    return longestStreak;
}
* Time: O(n3), Space: O()
better: sort:
9,1,4,7,4,3,-1,0,5,8,-1,6
sorted= -1,-1,0,1,3,4,5,6,7,8,9
Algo: If the current number and the previous are equal, then our current sequence is neither extended nor broken, 
so we simply move on to the next number. If they are unequal, then we must check whether the current number extends the sequence
 (i.e. nums[i] == nums[i-1] + 1). If it does, then we add to our current count and continue. Otherwise, the sequence is broken, 
 so we record our current sequence and reset it to 1 (to include the number that broke the sequence). It is possible that the last element of nums is part of the longest sequence, 
 so we return the maximum of the current sequence and the longest one
___
code: 
        if (nums.length == 0) {
            return 0;
        }

        Arrays.sort(nums);

        int longestStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i-1]) {
                if (nums[i] == nums[i-1]+1) {
                    currentStreak += 1;
                }
                else {
                    longestStreak = Math.max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        return Math.max(longestStreak, currentStreak);
    }
    * time: O(nlogn),space: O(1)
    BEST : algo: 
     unordered set for o(1) lookup
     for each elemnet (it) of set, appracoh in two ways if its succerror element is not present or not, or its precessdderrecor elemnnt is present or not
     for ex:  for a x if  its x-1 is not presetn, means its smallest no of a sequece;
     then set x as current_num
     and incremnet current_length till x+1 is present in the sequcnec.
     if x+1 not presetn , update the longest sum.
     and check for next parent it, if its smallest or not.. this way we will move for each it of nums.
     * time: O(n),space: O(n)

*/

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> s(nums.begin(), nums.end()); // for O(1) lookup time.

    // for (auto x : s)
    //     cout << x << " "; //! set stored ordered, unordered_set stores unsorted.
    // cout << endl;
        int longestSequence = 0;

    for(auto it: nums)   //o(n)
    {   int current_sequence=1;

        if(s.find(it+1)==s.end()) // means its the largest no among the sequnce. o(1)
        {
            int current_num=it;
            while(s.find(current_num-1)!=s.end()) // means lesser no is present in present . o(1)
            {
            current_sequence++;
            current_num=current_num-1; //! very imp otherwise infi loop
            }
        }
        longestSequence=max(current_sequence,longestSequence);

    }
    return longestSequence;
}

int main()
{
    FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;
    vector<int> v = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    cout<<longestConsecutive(v);
    return 0;
}

