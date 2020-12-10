//problem link: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/
// tutorial linK: https://www.youtube.com/watch?v=wq6TCikSzpk&list=PL2q4fbVm1Ik4JdzE2Bv_UUGBz0TXEIrai&index=7&ab_channel=CodeNCode
// learning: path compression , we can store required thing in paretns.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, n) for (int i = 1; i <= n; i++)

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:

i am shubham kumar singh
*Optimised:
* Time: O(), Space: O()
*/

int parent[100001];
vector<int> arr[100001];
int find(int a)
{
  if (parent[a] < 0)
    return a;
  // else{
  //   int x=find(parent[a]);
  //   parent[a]=x;
  //   return x;
  // }
  // one liner for above.
  else
  {
    return parent[a] = find(parent[a]);
  }
}
void unio(int var_u, int var_v)
{
  parent[var_u] = min(parent[var_u], parent[var_v]);
  parent[var_v] = var_u;
}

int main()
{
  
  int nodes, edges, u, v, x, y, q;
  cin >> nodes >> edges;
  // while(edges--){
  //     cin>>u>>v;
  //     arr[u].push_back(v);
  //     arr[v].push_back(u);
  // }

  Fo(i, nodes)
      parent[i] = -1 * i;
  while (edges--)
  {
    cin >> u >> v;
    int x = find(u), y = find(v);
    if (x != y)
      unio(x, y); //!we are unioning x,y (that is their parent) and not u, v.
  }
  //  printing parent...
  // Fo(i, nodes)
  //         cout
  //     << "for " << i << ": " << parent[i] << ",";
  // cout << endl;

  // taking queires...
  cin >> q;
  while (q--)
  {
    cin >> x >> y;
    int m = find(x), n = find(y);
    if (m == n)
    { // same set.
      cout << "TIE";
    }
    else if
        (parent[m] < parent[n])
      cout
          << x;
    else
    {
      cout << y;
    }

    cout << "\n";  }
  //!

  return 0;
}
