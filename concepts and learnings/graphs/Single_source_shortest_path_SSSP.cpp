//* problem link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
//* tutorial link: https://www.youtube.com/watch?v=-HH_hFIXVVA&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=7
// A simple representation of graph using STL
/*
store adjaceny list of graph.
find sssp for root vertex:
	visiting list, 
	if not visited passed distance and distance of previous + 1;
	store the vertices of girls location in arr.
	if minimum of distance list apperrs in girls arr... get it and break otherwise countinue for next index.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1001];
int vis[1001];
int dist[1001];
void dfsandSSP(int vertex, int dis)
{
	vis[vertex] = 1;							// mark as visited
	dist[vertex] = dis;							// assign  passed distance for that node
	for (auto child : arr[vertex])				// for every adjcaney list of the node
		if (!vis[child])						// if that child of a vertex is not marked
			dfsandSSP(child, dist[vertex] + 1); // will call dfs on that child node, and pass distance as +1, because from its partent node it will be dis..
												// distance of parent calling + 1.
}
int main()
{
	int n;
	cin >> n;
	int eg = n - 1;
	while (eg--)
	{
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	dfsandSSP(1, 0); // PASSING 1ST NODE, AND ITS DISTANCE WOULD BE ZERO
	int q;
	cin >> q;

	vector<int> locations;
	int mindis = 199999999;
	int ans = -1;
	//vis[i] contains node i present or not...
	//count[i] stores distance of node i from required node , in this case parent node...
	while (q--)
	{
		int current_girl; // current girl 
		cin >> current_girl;
		if (dist[current_girl] < mindis)
			mindis = dist[current_girl], ans = current_girl;
		else if (dist[current_girl] = mindis && current_girl < ans)
		{

			ans = current_girl;
		}
	}
	cout << ans;
	return 0;
}
