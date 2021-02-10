//* problem link: https://www.spoj.com/problems/PT07Y/
//* tutorial link: https://www.youtube.com/watch?v=EYLiRbXu3kc&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=8&ab_channel=CodeNCode
/*
1. no of connected component is 1
2. no of edges is 1;
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> arr[10001];
int vis[10001];
void dfs(int vertex)
{
    vis[vertex] = 1;
    for (auto x : arr[vertex])
    {
        if (vis[x] != 1)
            dfs(x);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    if (e != n - 1) // loop is there.
    {
        cout << "NO";
        return 0;
    }
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int count = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "for node " << i << " its" << endl; // for each vertex..
    //     for (auto y : arr[i])                       //printing its adjacency list
    //         cout << y << " ";
    //     cout << endl;
    // }
    for (int i = 1; i < n + 1; i++) // or till i<=n
    {
        if (vis[i] != 1) // initially all zero
        {
            dfs(i);
            count++;
        }
        if (count > 1)
            break;
    }
    if (count == 1)
        cout << "YES";
    else
    {
        cout << "NO";
    }

    return 0;
}
