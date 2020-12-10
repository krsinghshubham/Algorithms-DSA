#include <bits/stdc++.h>
using namespace std;
string repeat(string s, int n)
{n-=1;
  while (n--)
  {
    s += s[0];
   
  }
   return s;
}
int main()
{
  int t;
 cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      v.push_back(x);
    }
    const int max = *max_element(v.begin(), v.end());
    string ss="a";
    string s = repeat(ss, max);
    cout << s << endl;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
      for (int i = 0; i < *it; i++)
      {
        if (*it != max)
          s[*it] += 1;
      }
      cout << s << endl;
    }
  }
  return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define fl(i,a,n) for(int i=a; i<=n; i++)
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define test()  int tt;  cin>>tt;  while(tt--)
#define nl  cout<<"\n"
#define pii pair<int,int>
#define sz(v) ((int)(v).size())
#define get(a,st,en)  fl(i,st,en)       cin>>a[i]
#define pr(a,st,en)     fl(i,st,en)     cout<<a[i]<<" \n"[i==en]

const int MOD = 1e9+7;
void solve()    {
      int n;            cin>>n;
      int arr[n];       get(arr, 0, n-1);
      string s[n+1];
      s[0] = string(200, 'a');
      cout<<s[0]<<"\n";
      fl(i, 0, n-1) {
            s[i+1] = s[i];
            s[i+1][arr[i]] = (s[i+1][arr[i]] == 'a' ? 'b' : 'a');
            cout<<s[i+1]<<"\n";
      }
}
int main()  {
      fast;
      test()
            solve();
}
// credits @Benq
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/



