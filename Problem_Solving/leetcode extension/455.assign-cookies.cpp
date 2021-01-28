// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<iostream>
#include<algorithm>
//#include "commoncppproblem455.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

int findContentChildren(vector<int> &g, vector<int> &s)
{
    if (s.size() == 0)
        return 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    // sorted both factor and cookie size.
    int count = 0;
    for (int i = 0, sit = 0; i < g.size() && sit < s.size(); i++)
    {
        while (g[i] > s[sit] && sit < s.size())
        {
            // count++;
            sit++;
        }
        count++;
        sit++;
    }
    return count;
}
int main()
{
    vector<int>g={1,2};
    vector<int>s={1,2,3};
    cout<<findContentChildren(g,s);
    return 0;
}
