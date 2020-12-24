//problem link: https://leetcode.com/problems/maximum-subarray/submissions/
// tutorial  link: https://www.youtube.com/watch?v=w_KEocd__20&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=5&ab_channel=takeUforward
// problem: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9

// finding max sum is easy
// ! kadane algorithm
void printSubarray(int arr[], int l, int r)
{
  for(int i=l;i<=r;i++)
  cout<<arr[i]<<" ";
  cout<<endl;
}
// ____________
int maxSubArraySum(int arr[], int n)
{ // ! to find only max sum is implemented below
  // sum=0, max=int_min
  // if sum<0.. sum=0...
  // else store max.
  int sum = 0, maxsum = INT_MIN;
    int i=0,j=-1; // j-1 because gettting incremented at first index (0) in few case.
  for (int x=0;x<n;x++)
  {
    sum += arr[x]; // keep adding elements.. is current sum<0, initialize it to zero.
   
    //maxsum = max(sum, maxsum);
    if(sum>maxsum)
    maxsum=sum, j=x;  // update right index
    if (sum < 0)   // update lefta and right both to parent iteration.
      sum = 0, i=x,j=x;
    
  }
  cout<<" i :" <<i+1<< " j :"<<j<<endl;
  printSubarray(arr, i+1,j);
  return maxsum;

  //! if only max sub required and not the subarray then .... 
  
  / // sum=0, max=int_min
  / // if sum<0.. sum=0...
  / // else store max.
  
  int sum = 0, maxsum = INT_MIN;
  for (int x=0;x<n;x++)
  {
    sum += arr[x]; // keep adding elements.. is current sum<0, initialize it to zero.
    maxsum = max(sum, maxsum);
    if (sum < 0)
      sum = 0;
  }
  return maxsum;
  
}

int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.tie(NULL); //done to stop waiting of scanf/printf sync

  // int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; // to check with two arrays
  int a[] = {-2,1,-3,4,-1,2,1,-5,4};
  int n = sizeof(a) / sizeof(a[0]);
  int max_sum = maxSubArraySum(a, n);
  cout<<"max sum is : "<<max_sum;
  return 0;
}
