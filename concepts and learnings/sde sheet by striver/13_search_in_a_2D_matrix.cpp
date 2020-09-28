//! THEORY AND EXPLANATION FOR APPROACHES FOR BOTH THE PROBLEMS IS IN NOTEBOOK.
// * TWO PROBLEMS FOR THIS CONCEPTS ON THIS PAGE
// problem link: GFG: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
// problem link: Leetcode: below.
// tutorial linK:https://www.youtube.com/watch?v=ZYpYur0znng&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=13
// learning:
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define fo(i, n) for (int i = 0; i < n; i++)
// #define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //usually when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
// #define PI 3.1415926535897932384626
// #define INF 1000000000 //10 ^9

/*
Algorithm:
*Naive:
* Time: O(n^2), better: O(n*log(m)), Space: O(1)

*Optimised:
* Time: O(n), Space: O(1) // linear traversal.
*/
// bool search(int mat[][4], int size, int target)
// {
//     int i = 0;
//     int j = size - 1;
//     while (i < size && j >= 0)
//     {
//         if (mat[i][j] == target)
//         {
//             cout << "found at (" << i << "," << j << ")" << endl;
//             return true;
//         }
//         else if (mat[i][j] > target)
//         {
//             j--;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     return false;
// }
// int main()
// {
//     FASTIO_TEMPLATE;
//     int mat[4][4] = {{10, 20, 30, 40}, // suppose target 33
//                      {15, 25, 35, 45},
//                      {27, 29, 37, 48},
//                      {32, 33, 39, 50}};
//     bool x = search(mat, 4, 29);
//     if (x == false)
//         cout << " not found\n";

//     return 0;
// }
//* |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// problem link: LeetCode: https://leetcode.com/problems/search-a-2d-matrix/
// problem link: GFG is above.
// tutorial linK:https://www.youtube.com/watch?v=ZYpYur0znng&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=13
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //usually when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
*Naive:
* Time: O(), Space: O()

*Optimised:
* Time: O(), Space: O()
*/
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // for (auto x : matrix)
    // {
    //     for (auto y : x)
    //         cout << y << " ";
    //     cout << endl;
    // }
    // ? implement binary search on it.
     if(!matrix.size()) // when size zero
            return false;
    int n = matrix[0].size(); // we require no of colums.
    int m=matrix.size();
    int lo = 0;
    int high = n*m - 1; //! high is (n*m) and not n-1;
    while (lo <= high)
    { // 0 to 11
        int mid = lo + (high - lo) / 2;
        // cout<<"\ncurrently mid is: "<<mid<<" \n";
        // cout<<" maatrix current for mid is: "<<matrix[mid / n][mid % n]<<"\n";
        if (matrix[mid / n][mid % n] == target)
            return true;
        else if (matrix[mid / n][mid % n] > target)
        {
            high = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
        // cout<<"lo is: "<<lo;
        // cout<<" and high is: "<<high;
    }
    // cout<<"\n";
    return false;
}

int main()
{
    FASTIO_TEMPLATE;
    vector<vector<int>> Matrix = {{1, 3, 5, 7}, {10, 11, 12, 16}, {23, 30, 34, 50}};
    //  vector<vector<int>> Matrix = {{1},{3}};

    int target = 3;
    bool ans=searchMatrix(Matrix, target);
    if(ans)
    cout<<"found";
    else 
    cout<<"false";
    return 0;
}
