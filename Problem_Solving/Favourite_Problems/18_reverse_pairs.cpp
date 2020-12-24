//problem link: https://leetcode.com/problems/reverse-pairs/
// tutorial linK: https://www.youtube.com/watch?v=S6rsAlj_iB4&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18&ab_channel=takeUforward
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //done to stop waiting of scanf/printf sync
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
*Naive:
* Time: O(n^2), Space: O(1)

*Optimized:
* Time: O(nlog(n))+O(n) for(algorithm of merge sort, and counting operation respectively... 
counting is o(n) because we are not starting j from 1st index of right array every time , 
instead we are resuming from the last stored value of j itself.), Space: O(N) for temporary array storage.
merge sort, returning result every time.
in merge function get result before  mergining
*/
int merge(vector<int> &nums, int low, int mid, int high)
{   int j=mid+1;
    int count=0;
    for(int i=low;i<=mid;i++)
    {
        while(j<=high && nums[i]>2LL*nums[j]) //! to convert 2 from int to long long so as the compiler auto converts it
        j++;   //? THIS IS ACTUALLY VERY SMART AS j IS  BEGINNING FROM LAST UPDATED POSITION ALONE, DOES DECREASING TIME COMPLEXITY.
        count+=j-(mid+1); // O(N)

    }


    //* now merging
    // int n1 = mid - low + 1;
    // int n2 = high - mid;
    int left = low, right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
            temp.push_back(nums[left++]);
        else
        {
            temp.push_back(nums[right++]);
        }
    }
    while (left <= mid)
        temp.push_back(nums[left++]);
    while (right <= high)
        temp.push_back(nums[right++]);
    // up till here temp array with sorted element created,put it back in nums
    for (int i = low; i <= high; i++)
        nums[i] = temp[i - low];
    return count;
}
int mergeSort(vector<int> &nums, int low, int high)
{
    int result = 0;

  
    if (low <high)
    {
        int mid = low + (high - low) / 2;
        result += mergeSort(nums, low, mid);
        result += mergeSort(nums, mid + 1, high);
        result += merge(nums, low, mid, high);
    }
    return result;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}
int main()
{
    FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;
    vector<int> nums = {40, 25, 19, 12, 9, 6, 2};

    cout<<reversePairs(nums)<<endl;

    for (auto x : nums)
        cout << x << " ";
    return 0;
}
