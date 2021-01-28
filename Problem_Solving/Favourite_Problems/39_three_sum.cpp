//problem link: https://leetcode.com/problems/3sum/
// tutorial linK: https://www.youtube.com/watch?v=WdaeixEeAVs
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
Algorithm: 1: 3 loop O(N^3)
Algorithm: 2: 
  iterate once and store all the elements and their occurrences in a set. 
  run 2 loop , and check for a,b if -(a+b) exist in set or not, if exist then its 
    a match, and reduce the count by -1 in set. Time: O(N^2) , Space: O(N)
Algorithm 3: 
  Two pointer approach: 
    1. sort: 
    2. for elements i= 0 to n-2, j= i+1 , k=n-1 
      for each i, we will run j and k ans two pointer till j<k
      will jump i,j,k such that it does not iterate through same no.

* Time: O(N^2), Space: O(1)
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
  vector<vector<int>> ans;
  int n = nums.size();
  if (n <= 2)
    return ans;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n - 2; i++)
  {

    int req = -1 * nums[i];
    int j = i + 1;
    int k = n - 1;
    while (j < k) // un till cross over.
    {
      int twoSum = nums[j] + nums[k];
      if (twoSum == req)
      {
        vector<int> tec;
        tec.push_back(nums[i]);
        tec.push_back(nums[j]); // can't do j++ here and k-- , because next two checks will be disturbed.
        tec.push_back(nums[k]); //
        ans.push_back(tec);
        while (j < k && nums[j + 1] == nums[j]) // 1st check j<k and then right part, otherwise error in LC.
          j++;
        while (j < k && nums[k - 1] == nums[k])
          k--;
        j++;
        k--;
      }
      else if (twoSum < req)
        j++;
      else if (twoSum > req)
        k--;
    }
    if (i + 1 < n)
      while (i + 1 < n && nums[i + 1] == nums[i])
        i++;
  }
  return ans;
}

int main()
{
  FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;
  vector<int> nums = {-2, 0, 0, 2, 2};

  vector<vector<int>> x = threeSum(nums);
  for (auto p : x)
  {
    for (auto y : p)
      cout << y << " ";
    cout << endl;
  }

  return 0;
}
