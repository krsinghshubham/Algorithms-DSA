//problem link:https://leetcode.com/problems/4sum/
// tutorial linK:
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
* naive Solution with t.complexity is dicsussed in notebook.
* Time: O(), Space: O()

*Optimized:
* Time: O(n^3), Space: O(1)
algorithm in notebook
*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  vector<vector<int>> result;
  if (nums.size() == 0)
    return result;

  int n = nums.size(); //sorting required
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {                                        //  { 1, 1, 1 , 2, 2, 3, 3, 4, 4, 4}
      int initialSum = nums[i] + nums[j];    //2
      int requiredSum = target - initialSum; // 7
      int front = j + 1;
      int back = n - 1;
      while (front < back)
      {
        int twoSum = nums[front] + nums[back];
        if (twoSum < requiredSum) //5 < 7
          front++;
        else if (twoSum > requiredSum)
          back--;
        else
        {
          vector<int> quads(4, 0);
          quads[0] = nums[i];
          quads[1] = nums[j];
          quads[2] = nums[front];
          quads[3] = nums[back];
          result.pb(quads);

          // handling jump of front and back;
          while (front < back && nums[front] == quads[2])
            ++front; // for 1st itert. nums[front] will be same
          while (front < back && nums[back] == quads[3])
            --back; // for 1st itert. nums[back] will be same
        }
      }
      // handling jump of j...
      while (j + 1 < n && nums[j + 1] == nums[j]) //! j+1 < n and not j<n because parent loop also incrementing i and j ecery step, so we need to stay two step back. similarly for i
        ++j;
    }
    // handling jump of i
    while (i + 1 < n && nums[i + 1] == nums[i])
      ++i;
  }
  return result;
}

int main()
{
  FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;
  vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
  int target = 9;
  vector<vector<int>> x = fourSum(nums,target);
  for (auto p : x)
  {
    for (auto y : p)
      cout << y << " ";
    cout << endl;
  }

  return 0;
}
