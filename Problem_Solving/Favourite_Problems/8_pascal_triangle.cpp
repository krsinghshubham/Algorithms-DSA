//problem link: https://leetcode.com/problems/pascals-triangle/
// tutorial linK: https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8
// learning:
/*
3 types : 
            1. to print a element directly which will be ... nCr .... 
              
                for type 1 tc will be O(1)
            2. to print an entire row...
                for type 2 tc will be O(N) ... to print each element of row, one element calculation take O(1)
            3. to print an entire triangle.... 
                smartly will use previous calculations of nCr in a row.
            Given prblm is of type 3....
            observation....
                  n from 0 to n-1.
                r from 0 to n.
                total no of elements in a row= n+1 (coz n is from zero to n-1.) 
                spacing waigrah ki dikkat nahi in leetcode

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:

* Time: O(n^2), Space: O(1) n= rows
*/

  vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>>result;
        vector<int>rowElems;
        for(int row=0;row<=numRows-1;row++)
        {
            int temp=1;
            rowElems.push_back(temp); // 1st elment always ie., for nC0
            for(int elemPos=1;elemPos<=row;elemPos++) // from 2nd elemPOs.
            {
                temp=temp*(row-elemPos+1) /elemPos;
                rowElems.push_back(temp);
            }
            result.push_back(rowElems);
            rowElems.resize(0);
        }
        return result;
    }