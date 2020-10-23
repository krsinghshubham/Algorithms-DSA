//problem link:https://leetcode.com/problems/find-the-duplicate-number/
// learning:
// this is intital template

//APPROCAH 1 CAN HANDLE MULTIPLE DUPLICATES AND PRINT ALL OF THEM BUT SLOWER run time 24ms for aprocah 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626


int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  vector<int> nums = {1,3,4,2,2};
  int result = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    nums[(nums[i] % n)] += n;
  }
  //  for(auto k:nums)
  // cout<<k<<" ";

  cout<<endl;
  vector<int> vx;
  for (int i=1;i<n;i++)
  {
    if (nums[i]> 2*n)  // impprtont comaprison

    {
      cout<<i;
      break;
    }
  //   else
  //   {
  //     continue;
  //   }
  }
  // printing all duplicate elemetns
  for(auto k:vx)
  cout<<k<<" ";

  // cout<<endl;
  // return vx[0];
  return 0;
}

//APPROACH 2 FOR ONE DUPLICATE IN CYCLE ONLY . run t=16ms
// submitted for above link.
// solution: https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2&t=0s
// gfg link
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
      slow=nums[0];
      fast=nums[0];
      do{
        slow=nums[slow];
        fast=nums[nums[fast]];
      }
      fast=nums[0]; // put anyone slow or fast to begin of arr and then increment once for both , nexxt collison is the repetitve elemnt
      while(slow!=fast)
      (
        slow=nums[slow];
        fast=fast[fast];
      )
      return slow;
    }
};