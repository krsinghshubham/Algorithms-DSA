//problem link:https://www.hackerearth.com/challenges/competitive/code-monk-disjoint-set-union-union-find/algorithm/teachers-dilemma-3/
// tutorial linK: https://www.youtube.com/watch?v=_0YjD1HcWW8&list=PL2q4fbVm1Ik4JdzE2Bv_UUGBz0TXEIrai&index=5&ab_channel=CodeNCode
// learning: disjoin to find no of groups
// TEACHERS DILEMMA.
// ! thoery in notebook.
//refrence code //https://ideone.com/cHdgmU
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
int parent[100001];

int find(int a) // retunr parent.
{

  while (parent[a] > 0)
    a = parent[a];

  return a;
}
void unions(int a, int b)
{
  parent[a]+=parent[b]; //adding size of set b to set a ... add two negative to get neative.
  parent[b] = a; //making a , parent of new set
}
int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.tie(NULL); //usuall when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
  int n, m;
  cin >> n >> m;
  // memset(parent, -1, sizeof(parent));
  for (int i = 1; i <= n; i++)
    parent[i] = -1;  	//initializing

  while (m--)
  {
    int a, b;
    cin >> a >> b;
    a=find(a), b=find(b); // ! WE ARE FINDING ND THEN RETURNING THE PARENT TO THE VERTEX.
    if (a!=b)
      unions(a, b);
  }
  ll result = 1;
  for (int i = 1; i <= n; i++)
  {
    if (parent[i] <= 0)
      result = (result*abs(parent[i]))%1000000007;
  }
  cout << result;
  return 0;
}


// int main()
// {
// 	int n , m , a , b;
// 	cin>>n>>m;

		
// 	while(m--)
// 	{
// 		cin>>a>>b;
// 		a = find(a) , b = find(b);
		
// 		if(a != b) Union(a , b);
// 	}
	

// 	cout<<res;
// }


