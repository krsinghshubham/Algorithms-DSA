//problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// tutorial linK: https://www.youtube.com/watch?v=qtVh-XEpsJo
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
Sliding Window : 
* Time: O(N), Space: O(N)
*/
                       // * using set fails for multiple test case.
                       /*
*extreme cases:
    string str = "bbbbb";
    string str = "cdd";
    string str = "ccd";
    string str = "geeksforgeeks";
*/

int lengthOfLongestSubstring(string s)
{
    int maxlen = 0;
    /*
        algo: 
            1. left, right... , make unordered map with indexes. 
        */
    int left = 0, right = 0;
    int size = s.size();
    unordered_map<char, int> indexhash;
    for (int i = 0; i < size; i++)
    {
        if (indexhash.find(s[i]) != indexhash.end()) // the current index already exist.,update the left to +1.
            left = max(left, indexhash[s[i]] + 1);   //? imp:what if left found in a subarray which is already contradicted we need left which is greater than prvious left.

        maxlen = max(maxlen, right - left + 1); // will check for each iteration, so to not miss left.
        indexhash[s[i]] = i;
        right++;
    }
    return maxlen;
}

int main()
{
    //  FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;

    string str = "bbbbb";
    // string str = "cdd";
    // string str = "ccd";
    // string str = "geeksforgeeks";
    // string str= "abcabcbb";
    cout << "The input string is " << str << endl;
    int len = lengthOfLongestSubstring(str);
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len;
    return 0;
}