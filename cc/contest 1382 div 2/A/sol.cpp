
#include <bits/stdc++.h>
using namespace std;

int main()
{

  int t;
  cin >> t;
  while (t--)
  {

    int m, n;
    cin >> m >> n;
    vector<int> arr;
    vector<int> brr;
    for (int i = 0; i < m; i++)
    {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      brr.push_back(k);
    }

    vector<int> v(arr.size()+brr.size());
  
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    vector<int>::iterator it, st;

    it = set_intersection(arr.begin(),
                          arr.end(),
                          brr.begin(),
                          brr.end(),
                          v.begin());


    if(it-v.begin()==0)
    cout<<"NO"<<endl;
    else
    {
      cout<<"YES"<<endl<<1<<" "<<v[0]<<endl;
    }
    
  }
  return 0;
}
