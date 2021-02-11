//problem link: https://leetcode.com/problems/power-of-two/submissions/
// Reference linK: https://www.youtube.com/watch?v=YlmYATs5nXc&ab_channel=PrakashShukla
// learning:    counting no of set bits. and important observations.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FGV9Jm2u7rmsCe65wKzPTw5jtS38n2tVEGi ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
                       /*
Algorithm: 1
!BETTER
* Time: O(N), Space: O(1)
*/
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    // to count number of set bits of a decimal no N. 
    int count = 0;
    for (int i = 0; i < 32; i++) // max 32 bits. 4=0100
        count += (n >> i) & 1;   // first shift then AND, also SHIFT operator DOES NOT MODIFY the number.
    if (count == 1)
        return true;
    return false;
}
//? ___________________________________________________
/*
Algorithm:
! OPTIMIZED:
* Time: O(1), Space: O(1)
1	1
2	10
3	11
4	100
5	101
6	110
7	111
8	1000 
todo ::  we can see that AND of required and Its precediing no is 0.

*/
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    if ((n & n - 1) == 0)
        return true;
    return false;
}

