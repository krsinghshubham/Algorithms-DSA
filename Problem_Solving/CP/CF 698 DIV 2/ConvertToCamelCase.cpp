// CPP program to convert given sentence
/// to camel case.
#include <bits/stdc++.h>
#include<string>
using namespace std;

// Function to remove spaces and convert

string convert(string s)
{
    int c = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        c++;

        if (s[i] == ' ')
        {
            s[i] = '_';
            s[i+1]=toupper(s[i+1]);
            // c++;
            continue;
        }
        
    }
    // imp...
    return s;
}

// Driver program
int main()
{
    string str;
    getline(cin,str);
    cout<<convert(str);

    return 0;
}
