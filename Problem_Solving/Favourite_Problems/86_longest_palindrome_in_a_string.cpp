//problem link: https://leetcode.com/problems/reverse-words-in-a-string/
// Reference linK: https://www.youtube.com/watch?v=tEbOmwxmuls&ab_channel=codebix
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
// * total 4 algorithms.
/*
! Algorithm: 1: 
brute: generate all subtring using twoo loops, check if its palindrome or not and counter for max length
* Time: O(n^3), Space: O(1)
{
  code done,easy only.
}
*/

/*
! Algorithm: 2:
dp by makin a table bottom up.
* Time: O(n^2), Space: O(n^2)


*/
/*
! Algorithm: 3: 
two pointer, two lengths for each centre. 
one length to check possibility of even length palindrome by passing i an i.
2nd length is to check possibiltiy of odd length palidrome by passing i and i+1.
Reference: https://www.youtube.com/watch?v=OwjIfAy1OqA&ab_channel=jayatitiwari 
* Time: O(n^2), Space: O(1)
*/
/*
! Algorithm: 4
Manacher’s Algorithm – Linear Time Longest Palindromic Substring 
* Time: O(n), Space: O(1)
*/

int main()
{

  
  return 0;
}