
#include <iostream>
#include <math.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
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
 int d;
 char a,b;
 int x,y;
 cin>>d;
 cin>>a>>b;
 cin>>x>>y;
 int p=((int)b-(int)a)+1;
//  cout<<p<<endl;
 int q=y-x+1;
//  cout<<q<<endl;
 int result=pow(q,4)*pow(p,2)*d;
 cout<<result;
}