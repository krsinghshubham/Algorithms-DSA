//problem link:https://leetcode.com/problems/reverse-words-in-a-string/
// Reference linK:
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
handle 3 cases: 
leading spaces
in between spaces
trailing spaces.
take a data structure , store in it only if the size of string is more than 1. 
print in reverse. here we are taking vector.
NOte... 1. we can take stack to make things easy... 
        2. other methods like revrese the words by swapping waigrah wont handle the 3 special cases mentioned above.
* Time: O(n), Space: O(n)
*/

int main()
{
    //"the sky is full of water"     //"  the sky is full of water"     //"the     sky is full of water"     //"the sky is full of water   "
    string s;
    getline(cin, s);
    vector<string> v;
    s += ' '; // ! adding leading space to original string to handle last word properly.
    int n = s.length();
    int updated_starting_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            updated_starting_index = i;
            int count = 0;
            while (s[i] != ' ')
            {
                i++;
                count++;
            }
            v.push_back(s.substr(updated_starting_index, count)); //// ! yes we need to pass the count and not till index in 2nd pReference.
        }
    }
    //* all good after this.
    string result = "";
    for (auto x = v.end() - 1; x != v.begin(); x--) // prnt in rev. //! till v.end()-1 is the last element. imp.
    {

        result += *x;
        result += " ";
    }
    result += *v.begin(); // adding seperately to handle white space.
    cout << result;
    return 0;
}
