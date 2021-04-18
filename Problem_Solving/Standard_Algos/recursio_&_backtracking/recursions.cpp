
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000007

void possiblePaths(int m, int n, string osf, int &count, int i, int j)
{
  // base:
  if (i == m - 1 && j == n - 1) // reached final position
  {
    cout << osf << endl;
    count++;
    return;
  }
  if (i > m - 1 || j > n - 1)
    return;
  possiblePaths(m, n, osf + "R", count, i, j + 1);
  possiblePaths(m, n, osf + "D", count, i + 1, j);
  // possiblePaths(m, n, osf + "->", count, i + 1, j+1);
}
void printInLexicoGraphicOrder(int n, int i) //!  IMPORTANT
{
  //base:
  if (i > n)
    return;

  // recursive assumption
  cout << i << endl;

  for (int j = (i == 0 ? 1 : 0); j <= 9; j++) // if i=0, then begin with 1, else begin with 0
  {
    printInLexicoGraphicOrder(n, 10 * i + j);
  }
}
void printAllPermutation(string str, string osf)
{
  if (str.length() == 0)
  {
    cout << osf << endl;
    return;
  }
  unordered_set<char> uset;
  for (int i = 0; i < str.size(); i++)
  {
    if (uset.count(str[i]) == 0)
      printAllPermutation(str.substr(0, i) + str.substr(i + 1), osf + str[i]);
    uset.insert(str[i]);
  }
}

int main()
{
  clock_t begin = clock();
  //* --------------------------------
  printAllPermutation("AAC", "");
  //*---------------------------------
  clock_t end = clock();
  cout << "\n\nExecute In: " << double(end - begin) / CLOCKS_PER_SEC << " ms";
  return 0;
}
