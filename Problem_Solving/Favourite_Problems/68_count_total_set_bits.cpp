//problem link:https://leetcode.com/problems/counting-bits/
// Reference linK:   https://www.youtube.com/watch?v=awxaRgUB4Kw
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FGV9Jm2u7rmsCe65wKzPTw5jtS38n2tVEGi ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
BRUTE: we can do in O(N*sizeof(int))
OPTIMIZED : 
institution building : 
1. odd nos have 1 in LSB, even nos have 0 in lsb.  ex: 4=100, 5=101
2.right shift by 1 is equivalent to no/2. 
3. since even no have 0 at LSB, right shift will conserve no of set bits 
4. and since odd no have 1 at LSB , right shift will reduce no of set bits by 1. 
so , ex find for 8.. 
we need to know 4, we need to know 2, we need to know 1, we need to know 0.
  another ex: find for 9...
  we need to know 4... (we know 4 from previous example... going to use dp.)
    we need to find for 7
    find for 3.. find for 1... find for 0. 
        so , u got the initituion .. build the memo table. 

* Time: O(n), Space: O(n)
*/
vector<int> countBits(int num)
{
  vector<int> result(num + 1);
  result[0] = 0; // coz zero will have 0 set bits.
  for(int i=0;i<4;i++)

  // for (int i = 0; i <= num++)
    result[i] = result[i / 2] + i % 2; // right shift equivalent to divide by 2, and add 1 in case of odd nos.
  return result;
}
