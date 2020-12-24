//problem link: https://leetcode.com/problems/subarray-sum-equals-k/solution/
// tutorial linK: https://www.youtube.com/watch?v=bqN9yB0vF08&t=407s&ab_channel=thecodingworld
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
Naive: iterate for all subarrays
* Time: O(n^2), Space: O(1)
! what if we need to find the max length of subarray to, in that case we would use unorred_map<int, <int, int>> to store inices of cummulative sum too.
algo :
1. unodered map, value and count of value.
count of value because if difference is occuring two or more times before than from currnet indexes all such subarrays will be possible.
add keep on adding the commulative sum parallely too.
check if the diffrence is prenst in map or not, if present update the count by value in the hashmap for that difference.
* Time: O(n), Space: O(n)
*/
                       //* mine code and implementation

int subarraySum(vector<int> &nums, int k)
{
    // M A H A D E V
    unordered_map<int, int> hashmap;
    int count = 0, s = 0;
    hashmap.insert(make_pair(0, 1)); // initiall commuative sum is zero, because one single index ewalling to target have to be counted.
                                     // let array be {3,4,7,2,-3,1,4,2, 1}; and target sum be =7;
    int n = nums.size();
    fo(i, n)
    {
        s += nums[i];
        if ((hashmap.find(s-k) != hashmap.end())) // means difference exits in haspam // and its S
        {
            // hashmap[s]++;
            count += hashmap[s-k];
        }

        if ((hashmap.find(s) == hashmap.end()))
            hashmap[s] = 1;
        else
        {
            hashmap[s]++;
        }

        cout << "for " << i << " its : of which commulative sum is : "<<s << endl;
        for (auto x : hashmap)
            cout << x.first << " " << x.second << endl;
        
        cout<<"count is "<<count<<endl<<endl;
    }
    return count;
}
int main()
{
    int arr[] = {3, 4, 7, 2, -3, 1, 4, 2,1};
    // int arr[] = {1};

    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    int requiredsum = 7; // making genreic for all sums.
    cout << "NO of such subarray is : \n"
         << subarraySum(v, requiredsum);
    ;
    return 0;
}