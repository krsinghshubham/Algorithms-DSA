//problem link: https://www.spoj.com/problems/DQUERY/
// tutorial linK: https://www.youtube.com/watch?v=aZG0I9MM03s&list=PL2q4fbVm1Ik7Ds5cuaoOmExjOQG31kM-p&index=3

// code refrence: https://ideone.com/W4m7Vc

// learning: complexity is based on pointer movement which is based on block size and block size based on sqrt(n)
// * see at bottom Note for complexity analysis.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   //usually when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
*Naive:
* Time: O(n*no_of_queiries), Space: O()

*Optimised:
* Time: O(sqrt(no_of_queires)), Space: O(N) (that is for frequecy array)
*/

int main()
{
  FASTIO_TEMPLATE;
  
  return 0;
}




//* bottom Note: 
/*
 Have a look at our code above, the complexity over all queries is determined by the 4 while loops. First 2 while loops can be stated as “Amount moved by left pointer in total”, second 2 while loops can be stated as “Amount moved by right pointer”. Sum of these two will be the over all complexity.

Most important. Let us talk about the right pointer first. For each block, the queries are sorted in increasing order, so clearly the right pointer (currentR) moves in increasing order. During the start of next block the pointer possibly at extreme end will move to least R in next block. That means for a given block, the amount moved by right pointer is O(N). We have O(Sqrt(N)) blocks, so the total is O(N * Sqrt(N)). Great!

Let us see how the left pointer moves. For each block, the left pointer of all the queries fall in the same block, as we move from query to query the left pointer might move but as previous L and current L fall in the same block, the moment is O(Sqrt(N)) (Size of the block). In each block the amount left pointer movies is O(Q * Sqrt(N)) where Q is number of queries falling in that block. Total complexity is O(M * Sqrt(N)) for all blocks.

There you go, total complexity is O( (N + M) * Sqrt(N)) = O( N * Sqrt(N)) 
*/