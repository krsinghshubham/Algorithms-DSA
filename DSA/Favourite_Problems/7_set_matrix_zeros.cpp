//problem link: https://leetcode.com/problems/set-matrix-zeroes/
// tutorial linK: https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7&ab_channel=takeUforward
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
// ! algo in notebook, this is optimised of better approach where we are creating dummy rows and columns in matrix itself.
void setZeroes(vector<vector<int>> &matrix)
{ // creating dummy areas in matrix itself
  bool flag = true;
  int rows = matrix.size();       // !thats how we can take no of rows.
  int columns = matrix[0].size(); // ! thats how we can take no of colums
  for (int i = 0; i < rows; i++)
  {
    if (matrix[i][0] == 0)
      flag = false; // if in any row[0]== zero, will set flag as false.
    for (int j = 1; j < columns; j++) //! from j=1      because what if matrix[2][0]=0 and matrix[0][0]!=0 
      if (matrix[i][j] == 0)
        matrix[i][0] = matrix[0][j] = 0; // for completing dummy matrix , parent row and column
  }
  // uptil now dummy matrix created and flag set.
  for (int i = rows - 1; i >= 0; i--) //! i is not checked for equaltiy because 0th column 1st element will be zero only for that particular element only if flag=false.
  {
    for (int j = columns - 1; j >= 1; j--) //* !uptill j==1 only, parent column will be handle based on flag only.
    {
      if (matrix[i][0] == 0 || matrix[0][j] == 0)
        matrix[i][j] = 0;
    } // uptill here its fine for general case...

    if (flag == false)
      matrix[i][0] = 0; // becuase that means zero exist in that column.
  }
}
int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.tie(NULL);                                                 //usuall when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
                                                                  //  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}; // vector 1.
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 1, 1}, {0, 1, 1}}; //vector 2. delicate case // expected output= (0,1,1),(0,1,1),(0,0,0)

  //vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}; //vector 3.

  //vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}}; //vector 4.
  setZeroes(matrix);
  for (auto x : matrix)
  {
    cout << "( ";
    for (auto it : x)
      cout << it << " ";
    cout << " )";
  }
  return 0;
}
