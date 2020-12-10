//problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
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
! failed algorithm : next Up : Sliding Window : 
* Time: O(), Space: O()
*/
// * using set fails for multiple test casse.
/*
*extreme cases:
    string str = "bbbbb";
    string str = "cdd";
    string str = "ccd";
    string str = "geeksforgeeks";
*/
// int lengthOfLongestSubstring(string s)
// {
//     int maxlen = 0;
//     int n = s.length();
//     int count=0;
//     unordered_set<char> st;
//     for (int i = 0; i <n; i++)
//     {
//         // if(s[i]!=s[i+1])
//         
//         while (st.find(s[i]) == st.end() && i <n ) // to stop infinite loop
//         {
//             st.insert(s[i]);
//             count++;
//             i++;
//         }
//         // if (s[i] == s[i - 1])
//         // {
//         //     count=0;
//         // }
//         // cout<<count<<endl;
//         maxlen = max(maxlen, count);
//         // count=0;
//         st.clear();
//          st.insert(s[i]);
//          count=1;
// 
//     }
//     return maxlen;
// }
int lengthOfLongestSubstring(string s)
{
    int maxlen = 0;
    int n = s.length();
    
    return maxlen;
}
int main()
{
    FASTIO_TEMPLATE;

    // string str = "bbbbb";
    // string str = "cdd";
    // string str = "ccd";
    string str = "geeksforgeeks";
    cout << "The input string is " << str << endl;
    int len = lengthOfLongestSubstring(str);
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len;
    return 0;
}