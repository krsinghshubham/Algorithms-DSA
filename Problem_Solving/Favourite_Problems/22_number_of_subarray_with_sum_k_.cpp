/*
TODO: IN SDE SHEET THE QUESTION IS ABOUT TO FIND LONGEST SUBARRAY SUM=0, IN THIS CODE ITS ABOUT "COUNT" OF SUCH SUBARRAYS.
 problem and solution for sde sheet
 : https://practice.geeksforgeeks.org/viewSol.php?subId=fe35885c285d1c676525ee1ddb497849&pid=700254&user=krsingh_shubham 
 tut: https://www.youtube.com/watch?v=xmguZ6GbatA&list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_&index=4&ab_channel=takeUforward
 TODO: FOR SDE QUESTION SEE UPWARDS.
 */
// ! IMPORTANT FOR MEMO.
//problem link: https://leetcode.com/problems/subarray-sum-equals-k/solution/
// Reference linK: https://www.youtube.com/watch?v=bqN9yB0vF08&t=407s&ab_channel=thecodingworld
// and codebix (mis kar raha imp. test cases notice we are updating count with the frequency and not by +1 ):
// https://www.youtube.com/watch?v=MHocw0bP1rA&ab_channel=codebix
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
Naive: iterate for all subarrays.
* Time: O(n^2), Space: O(1)
! what if we need to find the max length of subarray to, in that case we would use unordered_map<int, <int, int>> to store indices of cumulative sum too.
algo :
* Time: O(n), Space: O(n)
*/
                       //* mine code and implementation

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> hashmap;
    int count = 0, s = 0;
    hashmap.insert(make_pair(0, 1)); // initially commutative sum is zero, because one single index equalling to target have to be counted.
                                     // let array be {3,4,7,2,-3,1,4,2, 1}; and target sum be =7;
    int n = nums.size();
    fo(i, n)
    {
        s += nums[i];
        if ((hashmap.find(s - k) != hashmap.end())) // means difference exits in hashmap // and its S
        {
            // hashmap[s]++;
            count += hashmap[s - k]; // INCREASING COUNT BY FREQUENCY OF SUM AND NOT BY 1. FOCUSED PART TO UNDERSTAND.
        }

        if ((hashmap.find(s) == hashmap.end())) // means its not exist so insert it and put FREQUENCY AS 1.
            hashmap[s] = 1;
        else
        {
            hashmap[s]++;
        }
        // ? increase the FREQUENCY INSTEAD OF REPLACING BY 1. 
            // RESAON:  
                    /* 
                    see we can also have -ve numbers in our array 
                        because of them our cumulative sum might repeat therefore we are incrementing
                        our ans by the frequency of key not simply by one
                        try this testcase with both the approach
                        [1, 2, -3, 1, 2, -3, 1, 2, -3]   K = 3
                        first, solve it with simply incrementing by just 1
                        then solve this by incrementing by frequency
                        so, a larger sub array with cummulative sum neutralized to 0, the sum can be produced by considering older one too. 
        */
        cout << "for " << i << " its : of which commutative sum is : " << s << endl;
        for (auto x : hashmap)
            cout << x.first << " " << x.second << endl;

        cout << "count is " << count << endl
             << endl;
    }
    return count;
}
int main()
{
    int arr[] = {3, 4, 7, 2, -3, 1, 4, 2, 1};
    // int arr[] = {1};

    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    int requiredsum = 7; // making generic for all sums.
    cout << "NO of such subarray is : \n"
         << subarraySum(v, requiredsum);
    ;
    return 0;
}