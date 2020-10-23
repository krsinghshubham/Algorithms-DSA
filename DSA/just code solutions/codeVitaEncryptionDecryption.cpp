
// //#include <bits/stdc++.h>

// using namespace std;
// bool palindrome()
// int main()
// {
// int n1, n2;
// cin>>n1>>n2;
//     return 0;
// }
// C++ program to create Set of Pairs

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
//#include <bits/stdc++.h>
#include <set>
#include<unordered_set>

using namespace std;
typedef pair<char, char> pairs;

char repChar(string &str)
{
    int count = 0;
    unordered_set<char> h;
        int strl=str.length();

    for (int i = 0; i < strl; i++)
    {
        char c = str[i];

        
        if (h.find(c) != h.end())
        {
            return c;
            count++;
        }

        else // Else add element to hash set
            h.insert(c);
    }
    if (count == 0)
        return '!';

    // If there was no repeated character
    return '\0';
}

int main()
{
    string str;
    cin >> str;
        int strl=str.length();

    int n;
    cin >> n;
    set<pairs> s;
    string ns1, ns2;
    while (n--)

    {
        // for storing string jisme no repeating
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.length()==1){
            pairs gh=make_pair(s1.at(0), s2.at(0));
            s.insert(gh);
        }

       else if (s1.length() != 3)
        {
            char x = repChar(s1);
            char y = repChar(s2);
            if (x != '!' && y != '!')
            { // implement for size 3 too
                pairs p = make_pair(x, y);
                s.insert(p);
            }
            else if (x == '!')
            {
                ns1 = s1;
                ns2 = s2;
            }
            // include the case when no repeating  is found;
        }
        else
        {
            char x = repChar(s1);
            char y = repChar(s2);
            if (x != '!' && y != '!')
            {
                pairs p = make_pair(x, y);
                s.insert(p);
            }
            else if (x == '!')
            {
                ns1 = s1;
                ns2 = s2;
            }
            char x1, x2;
            for (int i = 0; i < 3; i++)
            {
                if (s1[i] != x)
                {
                    x1 = s1.at(i);
                    break;
                }
                else
                {
                    continue;
                }
            }
            for (int i = 0; i < 3; i++)
            {
                if (s2[i] != y)
                {
                    x2 = s2.at(i);
                    break;
                }
                else
                    continue;
            }

            pairs q = make_pair(x1, x2);
            s.insert(q);
        }
    }
    // cout<<endl;
    char nx1, nx2;
    int ns1l= ns1.length();
    if (ns1l >=1)
    {
        for (int i = 0; i < ns1l; i++)
        {
            bool bl = false;
            for (auto const &x : s)
            {
                if (x.first == ns1[i])
                {
                    bl = true;
                    break;
                }
            }
            if (bl == false)
            {
                nx1 = ns1.at(i);
                break;
            }
        }
    }
    int ns2l=ns2.length();
    if (ns2l>= 1)
    {
        for (int i = 0; i < ns2l; i++)
        {
            bool by = false;
            for (auto const &x : s)
            {
                if (x.second == ns2[i])
                {
                    by = true;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (by == false)
            {
                nx2 = ns2.at(i);
                break;
            }
        }
    }
    pairs zs = make_pair(nx1, nx2);
    s.insert(zs);

    // loop completed, set filled;
    // cout << endl; // display to be erased
    // for (int i = 0; i < str.length(); i++)
    // { // to check each elemtn of given string
    // auto it= s.find(str[i]);
    // cout<<it->second;

    // }

    // implement for ns1 and ns2

    // cout << endl;
    //  cout << str.length() << endl;
    // cout<<endl;
    for (int i = 0; i < strl; i++)
    {
        for (auto const &x : s)
        {
            if (x.first == str[i])
            {
                cout << x.second;
                break;
            }
        }
    }

    return 0;
}
