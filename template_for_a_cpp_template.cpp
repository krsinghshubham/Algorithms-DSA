//problem link:
// tutorial linK:
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   //usually when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:

* Time: O(), Space: O()
*/

int main()
{
  FASTIO_TEMPLATE;
  int tc;
  cin>>tc;
  while(tc--)
  {

  }
  return 0;
}



























































































// //#define gc getchar_unlocked
// //#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
// /*
// NO NEED OF THESE WILL GIVE SAME RESULT AS CIN AND COUT BECUASE WE ALREADY INCLUDED ...
// <    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);>

// #define si(x)	scanf("%d",&x)
// #define sl(x)	scanf("%lld",&x)
// #define ss(s)	scanf("%s",s)
// #define pi(x)	printf("%d\n",x)
// #define pl(x)	printf("%lld\n",x)
// #define ps(s)	printf("%s\n",s)
// */
// #define deb(x) cout << #x << "=" << x << endl // for debugging a value. passing x will print x="its value";

// //#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
// //#define mp make_pair
// // #define F first
// // #define S second
// #define all(x) x.begin(), x.end()
// // #define clr(x) memset(x, 0, sizeof(x))
// #define sortall(x) sort(all(x)) // all is defined above
// #define tr(it, a) for (auto it = a.begin(); it != a.end(); it++) //traversal
// #define PI 3.1415926535897932384626
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pl;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<pii> vpii;
// typedef vector<pl> vpl;
// typedef vector<vi> vvi;
// typedef vector<vl> vvl;
// //mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
// // int rng(int lim) {
// // 	uniform_int_distribution<int> uid(0,lim-1);
// // 	return uid(rang);
// // }
// // int mpow(int base, int exp);
// // void ipgraph(int n, int m);
// // void dfs(int u, int par);

// //const int mod = 1'000'000'007;
// //const int N = 3e5, M = N;
// //=======================

// // vi g[N];
// // int a[N];

// void solve()
// {
//   int i, j, m, n;
// }

// int main()
// {
//   //faster cin cout with scanf nd printf , keeping it.
//   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

//   //srand(chrono::high_resolution_clock::now().time_since_epoch().count());

//   int t = 1;
//   cin >> t;
//   while (t--)
//   {
//     solve();
//   }

//   return 0;
// }
// /*

// int mpow(int base, int exp) {
//   base %= mod;
//   int result = 1;
//   while (exp > 0) {
//     if (exp & 1) result = ((ll)result * base) % mod;
//     base = ((ll)base * base) % mod;
//     exp >>= 1;
//   }
//   return result;
// }
// */
// //considering
// /*
// void ipgraph(int n, int m){
// 	int i, u, v;
// 	while(m--){
// 		cin>>u>>v;
//     u--, v--;
// 		g[u].pb(v);
// 		g[v].pb(u);
// 	}
// }
// */
// //considering
// /*void dfs(int u, int par){
// 	for(int v:g[u]){
// 		if (v == par) continue;
// 		dfs(v, u);
// 	}
// }
// *?

// /* stuff you should look for
//     * int overflow, array bounds
//     * special cases (n=1?), set tle
//     * clearing previous arrays/adjacency list for more test cases
//     * size of array should be enough if declaring globally
//     * do smth instead of nothing and stay organized
    
// */