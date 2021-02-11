//problem link: https://leetcode.com/problems/unique-paths/
// Reference linK: https://www.youtube.com/watch?v=t_f0nwwdg5o&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=17&ab_channel=takeUforward
// learning: multiple approaches all discuused in notebook
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //done to stop waiting of scanf/printf sync
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
                       /*
Algorithm:
*Naive:
* Time: O(), Space: O()

*Optimized:
* Time: O(), Space: O()
*/
// int i = 0, j = 0, ct = 0;
int uniquePaths_with_recursion(int m, int n, int i, int j)
{
    // * Time: O(exp), Space: O(exp)
    if (i == m - 1 && j == n - 1) // base 1 reach end postion
        return 1;
    if (i > m - 1 || j > n - 1) // goes out of bound.
        return 0;
    else
        return uniquePaths_with_recursion(m, n, i + 1, j) + uniquePaths_with_recursion(m, n, i, j + 1);
}
int uniquePaths_with_recursion_Optimized_to_DP(int m, int n, int i, int j, vector<vector<int>> &DP)
{
    // * Time: O(m*n), Space: O(m*n) time because m*n states only , rest hast table will return , space because to store dp(m*n)+ recursion stack(m*n)
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i > m - 1 || j > n - 1)
        return 0;
    else if (DP[i][j])
        return DP[i][j]; // this step is reducing the comp to quadratic
    else
        return DP[i][j] = uniquePaths_with_recursion_Optimized_to_DP(m, n, i + 1, j, DP) + uniquePaths_with_recursion_Optimized_to_DP(m, n, i, j + 1, DP);
}
int pnc(int m, int n)
{

    //* Optimized.
    // * Time: O(m-1), Space: O(1) // discussed in notebook

    int total_ways = n + m - 2;
    int right = n - 1;
    int bottom = m - 1;
    double result = 1;
    int r = (right <= bottom) ? right : bottom; // will get answer from both of these, but to reduce time complexity will choose one only.
    while (r>0)
    {
        result *= ((double)(total_ways - r + 1) / r); //!converting to double , to avoid overflow
   
        r--;
    }
    cout<<"result is "<<(double)result<<endl;
    return round(result); // rounding, otherwise one integer more or less
}

int main()
{
    FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;
    int m, n;
    cin >> m >> n;
    cout << uniquePaths_with_recursion(m, n, 0, 0);
    cout << endl;
    vector<vector<int>> DP(m, vector<int>(n, 0)); //! most important
    cout << uniquePaths_with_recursion_Optimized_to_DP(m, n, 0, 0, DP);
    cout << endl;
    cout << pnc(m, n);
    return 0;
}