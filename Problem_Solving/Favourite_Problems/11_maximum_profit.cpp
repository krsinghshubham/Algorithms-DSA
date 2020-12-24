//problem link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// tutorial linK:https://www.youtube.com/watch?v=eMSfBgbiEjk&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=11&ab_channel=takeUforward
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (i = 0; i < n; i++)

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
int maxProfit(vector<int>&prices){
    int min=INT32_MAX;
    int profit=0;
    for(auto it=prices.begin();it!=prices.end();it++){
        if(*it<min)
        min=*it;
        if(*it-min>profit)
        profit=*it-min;
    }
    return profit;
}
int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.tie(NULL); //done to stop waiting of scanf/printf sync
  /*
  Algorithm: keep track of maximum profit.
  if minimum occurs then next profit will be from that minimum because even on right of new minimum a no occurs then that profit is required.
    sample to understand: 7,3,9,15,1,7. 
    profit... 3,15 ..... 1... suppose 99 then that profit will be from new minimum.... because we will get profit only while moving right.
  *time O(n), space O(1)
  */
 vector<int>price={7,1,5,3,6,4};
 cout<<maxProfit(price);
  return 0;
}

