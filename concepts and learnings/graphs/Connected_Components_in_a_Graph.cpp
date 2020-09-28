//problem link: https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
// learning: many basic graph concepts
// this is intital template
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626
int vis[10000] = {0}; // visiting list

void dfs(vector<int> arr[], int vertex)
{ // since the passed vertex is not visited...  so... 1st mark it as visited...
  vis[vertex] = 1;
  for (auto x : arr[vertex])
  { // for marking connected lists.
    if (vis[x] != 1)
      dfs(arr, x); // calling dfs on children of node recurssively...
  }
}
int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int noOfNodes, noOfEdges;

  cin >> noOfNodes;
  cin >> noOfEdges;
  // ? can we declare it outside .. yes declare it outside with some big size like vector<int> arr[100001] then we need to pass
  // ? argument for name of arr every time we will be passing it.
  vector<int> arr[noOfNodes + 1]; // because no of indices from 1 to n; 0 is for root
  // ! THIS IS A BIG MISTAKE, IF THE VALUE OF A NODE IS GREATER THAN THAT OF N =? IT WOULD FAIL, BECAUSE IT CANT STORE STORE VALUES GREATER THAN N WHILE DOING DFS....
  // ! FOR EXAMPLE CHECK BELOW TEST CASE..., declare it like ... vector<int> arr[100001]; and better declare it GLOBALLY TO SET ALL ZERO INITIALLY.
  // 8 7
// 1 2
// 2 3
// 2 4
// 2 5
// 4 6
// 6 8
// 6 9
// ! CORRECT WAY IS DECLARE IT GLOBALLY WITH A SIZE UPTO UPPER LIMITS and BETTER GLOBALLY
// ! CORRECTLY IMPLEMENTED IN "to_check_if_its_a_tree.cpp" file of this folder.
  int cc = 0;

  while (noOfEdges--)
  {
    int u, v;
    cin >> u >> v;
    arr[u].push_back(v);
    arr[v].push_back(u);
  }
  // ! for printing of graph: revise it important //dfs
  // for (int i = 1; i <= noOfNodes; i++)
  // {
  //   cout << "for node " << i << " its" << endl; // for each vertex..
  //   for (auto y : arr[i])                       //printing its adjacency list
  //     cout << y << " ";
  //   cout << endl;
  // }
  int count = 0;
  // algo for counting connected components;
  for (int i = 1; i <= noOfNodes; i++)
  {
    if (vis[i] != 1)
    {              // if that node is not visited, call dfs to it. dfs will assign all connected nodes to it as 1;
      dfs(arr, i); // * passing arr, because its not declared globally.
      cc++;
    }
  }

  cout << " no of connected components are : " << cc;
  return 0;
}
