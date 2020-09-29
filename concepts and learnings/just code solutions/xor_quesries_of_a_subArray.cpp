//problem link: https://leetcode.com/problems/xor-queries-of-a-subarray/
// tutorial linK:
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //usually when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:

* Time: O(), Space: O()
*/
// algo..
// calucate presum as commulativve of all xor
// then xor of range will be preusm[r]^presum[l-1]
// ofcouurse if l=0, then ans will be presum[r]
vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    int xorpresum[n];
    xorpresum[0] = arr[0];
    for (int i = 1; i < n; i++)
        xorpresum[i] = arr[i] ^ xorpresum[i - 1];
    vector<int> ans;
    int q = queries.size();
    for (int i = 0; i < q; i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        if (l == 0)
            ans.push_back(xorpresum[r]);
        else
        {
            /* code */
            ans.push_back(xorpresum[r] ^ xorpresum[l - 1]);
        }
    }
    return ans;
}


int main()
{
    FASTIO_TEMPLATE;
    int tc;
    cin >> tc;
    while (tc--)
    {
    }
    return 0;
}