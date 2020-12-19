// tutorial linK: https://www.youtube.com/watch?v=Y72QeX0Efxw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12&ab_channel=takeUforward
// problem linK: https://leetcode.com/problems/rotate-image/
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9

/*
*Naive:
* time: o(N^2), space: O(n^2)
Optimized:
* time: o(N^2+N^2), space: O(1)

take transpose, to do that  ([i][j] swap with [j][i])
the reverse each row.
*/
void rotate(vector<vector<int>> &matrix)
{
  int size = matrix.size();
  fo(i, size)
      fo(j, i)
          swap(matrix[i][j], matrix[j][i]); //*transpose took uptil here

  // revresing each row.
  for (int i = 0; i < size; i++)
  {
    reverse(matrix[i].begin(), matrix[i].end());
  }
  // for (auto x : matrix)
  // {
  //   cout << "[";
  //   for (auto y : x)
  //     cout << y << ",";
  //   cout << "]";
  // }
}
int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.tie(NULL); //usuall when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
  vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  rotate(matrix);
  return 0;
}