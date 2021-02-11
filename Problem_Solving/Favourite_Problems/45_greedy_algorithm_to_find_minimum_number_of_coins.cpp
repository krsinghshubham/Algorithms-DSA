//problem link: https://leetcode.com/submissions/detail/451151365/
// Reference linK:

// learning: (Not able to solve through greedy algorithm for all test cases, greedy won’t work for general
//test cases(for that we need to use DP) . Even striver clarified it. For general its in DP section again. )

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
Simple , refer the learning part.
* NlognN for sort, N for traversal , overall Nlogn. 
* Time: O(nlogn), Space: O(1)
*/
class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    if (amount == 0)
      return 0;
    int count = 0;
    sort(coins.begin(), coins.end(), [](int a, int b) {
      return a > b;
    });
    int n = coins.size();
    for (auto x : coins)
    {
      if (n > 1 && amount >= x)
      {
        count += amount / x;
        amount = amount % x;
      }
      if (n == 1)
      {
        if (amount % x == 0)
        {
          count += amount / x;
          ;
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