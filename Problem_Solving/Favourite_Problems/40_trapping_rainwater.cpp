//problem link: https://leetcode.com/problems/trapping-rain-water/
// tutorial linK: https://www.youtube.com/watch?v=gIZSOpW-SN0
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
  int trap(vector<int> &height)
    {
        /*
Algorithm:
Method 1: 
    1st and last index will always store 0 water.
    water will be min(leftMax,rightMax)-heightOfCurrent Building. 
    make two arrays of left max and right max ( for right max iterate from backwords) and store them. 
    for each indexes of 3 arrays( leftMax, rightMax, currentHeigh), sum up water.
* Time: O(N), Space: O(N)
*/
        int water = 0;
        int n = height.size();
        if(n<3) // minimum 3 required to store water.
        return 0; 
        int leftMax[n];
        int rightMax[n];
        int lm = 0;
        for (int i = 0; i < n; i++)
        {
            lm = max(lm, height[i]);
            leftMax[i] = lm;
           // cout<<leftMax[i]<<" ";
        }
        cout<<endl;
        int lr = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            lr = max(lr, height[i]);
            rightMax[i] = lr;
           // cout<<rightMax[i]<<" ";
        }
        for(int i=1;i<n-1;i++) // coz zero for 1st and last
        {
            water+=min(leftMax[i], rightMax[i])-height[i];
        }
        return water;
    }
};
// 1st method complete.
int trap(vector<int> &height)
    {
        /*
Algorithm:
Method 2: 
we need not to store left and right of heighest building, instead we can break into two parts: 
    store the higest building in one iteration.
    left of heightest building, because all of it will have same building as its right, after that 
    right side of the tallest building will have all of its building have same tallest building as its left. 
   
* Time: O(N), Space: O(1)
*/
       int n=height.size();
       if(n<3) return 0;
       int maxIndex=0;
       int max=0;
       for(int i=0;i<n;i++)
    {
        if(height[i]>max)
        {
            max= height[i];
            maxIndex=i;
        }
    }
    // for sure max building will not store any water, and ofc 1st and last building will also not. 
    int water =0;
    int leftMax=0;
    for(int i=0;i<maxIndex;i++)
    {
        if(height[i]>leftMax)
        leftMax= height[i];
        water+=min(leftMax, height[maxIndex])-height[i];
    }
    int rightMax=0;
       for(int i=n-1;i>maxIndex;i--)
    {
        if(height[i]>rightMax)
        rightMax= height[i];
        water+=min( height[maxIndex],rightMax)-height[i];
    }
    return water;
    }
};

int main()
{
// 12=1100
  int r=12;
  int k=(int)log2(r);
  //int k=(int)log2(r & -r)+1;
  cout<<k;
  return 0;
}

