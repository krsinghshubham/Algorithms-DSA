//problem link: https://www.spoj.com/problems/BUGLIFE/
// tutorial linK:/www.youtube.com/watch?v=nMQ4C3mOBEY&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=10&ab_channel=CodeNCode
// learning: clear array if same is being used for multiple TCs.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9

vector<int> arr[1000001];
int vis[1000000];
int col[1000001];
bool dfs(int node, int c)
{
    vis[node] = 1;
    col[node] = c;
    for (auto child : arr[node])
    {
        if (vis[child] != 1)
        { // agar child unvisited hai to... dfs call karo us pe with color inverted, beacuse child ka color ulta hona chhaiye.

            bool res = dfs(child, c ^ 1);
            if (res == false)
                return false;
        }
        else
        {
            if (col[node] == col[child])
                return false;
        }
    }
    return true;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.tie(NULL); //usuall when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
    int tc;
    cin >> tc;
    int nodes, edges, u, v, i;
    for (int iforitr = 1; iforitr <= tc; iforitr++)
    {

        cin >> nodes >> edges;
       

        for (i = 1; i <= nodes; i++) //!this is imporant to clear the previous arrays for each test cases UPTO TIL NODDES NOT EDGES.
        {
            arr[i].clear();
            vis[i] = 0;
            col[i] = 0;
            // cout << vis[i] << " ";
        } 
        while (edges--)
        {
            cin >> u >> v;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
     

        bool flag = true;
        for (int i = 1; i <= nodes; i++)
        {
            if (vis[i] != 1)
            {
                bool x = dfs(i, 1); // this will return for each connected componenet.
                if (x == false)
                    flag = false;
            }
        }
        if (!flag)
        {
            cout << "Scenario #" << iforitr << ":" << endl;
            cout << "Suspicious bugs found!" << endl;
        }
        else
        {
            cout << "Scenario #" << iforitr << ":" << endl;
            cout << "No suspicious bugs found!" << endl;
        }
    }

    return 0;
}
// 2
// 3 3
// 1 2
// 2 3
// 1 3
// 4 2
// 1 2
// 3 4
