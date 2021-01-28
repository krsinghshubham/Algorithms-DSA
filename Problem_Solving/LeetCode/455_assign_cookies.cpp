#include <vector>
#include <string>
#include<iostream>
#include<algorithm>

using namespace std;



class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    // sorted both child and cookies.
        int child=0,cookies=0;
    while(child<g.size() && cookies<s.size())
    {
        if(g[child]<=s[cookies])
            child++; // means move to next child
        cookies++; // either give or try next cookie.
    }
   
  return child;
}
};
int main()
{
    vector<int>g={1,2};
    vector<int>s={1,2,3};
    cout<<findContentChildren(g,s);
    return 0;
}
