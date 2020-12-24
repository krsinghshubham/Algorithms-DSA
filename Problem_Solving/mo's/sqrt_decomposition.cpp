//problem link:https://www.spoj.com/problems/RMQSQ/
// tutorial linK:https://www.youtube.com/watch?v=o7278rPg_9I&list=PL2q4fbVm1Ik7Ds5cuaoOmExjOQG31kM-p&index=2&t=0s&ab_channel=CodeNCode
// learning: we cant use sizeof(arr)/arr[0] for array passed as argument in function, because inside function passed array are considered as pointers.... so it ruturn in 1;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //done to stop waiting of scanf/printf sync
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
*Naive:
* Time: O(n), Space: O(1)

*Optimized:
* Time: O(sqrt(n)), Space: O(logN)
*/
vector<int> F;
int rmsq(int arr[],int size, int l, int r)
{
    int blk = floor(sqrt(size));
    int minmm = INT_MAX;
    int leftBlock = l / blk;
    int rightBlock = r / blk;
    // cout<<"\nleft block is : "<<leftBlock;
    // cout<<"\nright block is : "<<rightBlock;

    if (leftBlock == rightBlock)
    {
        for (int i = l; i <= r; i++)
            minmm = min(minmm, arr[i]); //* So this part is reducing the overaall complexity by checking only in intervals.1
        return minmm;
    }
   
    for (int i = l; i < blk * (leftBlock + 1); i++) //for left block
    {
        minmm = min(arr[i], minmm);
  
    }

    for (int i = leftBlock + 1; i < rightBlock; i++) // for middile blocks
        minmm = min(minmm, F[i]); 

    for (int i = rightBlock * blk; i <= r; i++)
        minmm = min(arr[i], minmm);

    return minmm;
}

int main()
{
    FAST_INPUT_OUTPUT_TEMPLATE;

    int n, q, l, r;
    cin >> n;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    // *  CREATING F ARRAY
    int min = INT_MAX;
    int blk = floor(sqrt(n));
    int i = 0;
    int blockSize = blk;
    for (i = 0; i < blockSize && i < n; i++) // blk=3.. array= 0,1,2,3,4,5,6,7,8,9
    {
        if (arr[i] < min)
            min = arr[i];
        // cout << "min here " << i << "-" << min << " for block " << blockSize;
        // cout << endl;
        // jumping to next block
        if (i + 1 == blockSize && i + 1 < n)
        {
            // cout << "minimum to be pushed in F is " << min << endl;
            F.push_back(min);
            min = INT_MAX;
            blockSize += blk;
        }
    }
    if (i <= blockSize) // note blockSize not blk
        F.push_back(min);
    //checking F
    // for (auto x : F)
    //     cout << x << " ";
    //* F ARRAY FILLED.

        cin >> q;

    while (q--)
    {
        cin >> l >> r;
        // printf("for %d and %d the minimum is: ",l,r);
        cout <<rmsq(arr,n, l, r) << endl;
        // cout<<endl;
    }
    return 0;

}
// 12
// 1 5 2 3 6 4 8 5 6 4 1 6
// 13
// 10 11
// 9 11
// 8 10
// 4 9
// 3 4
// 4 5
// 2 3
// 3 8
// 2 2
// 4 4
// 8 8
// 0 3
// 0 11