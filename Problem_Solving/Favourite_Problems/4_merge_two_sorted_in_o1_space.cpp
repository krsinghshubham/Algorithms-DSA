//problem link: from tutorial only, implementation by me || insetion sort.
// https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/ || gap method.
//tutorial: https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=4&ab_channel=takeUforward
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
//! APPROAH 1... Using insertion sort. complexity..O(m*n)time, O(1)space
void merge(int arr[], int brr[], int m, int n)
{                   // compare elements of arr with brr... if element of arr is smaller than brr its fine
                    // if greater swap and fix positon of arr into brr at suitable place in brr.
                    // to fix it at a suitable place
                    // int ar1[] = {1, 5, 9, 10, 15, 20};
                    // int ar2[] = {2, 3, 8, 13};
  int i = 0, j = 0; // i for arr, j for brr
  for (i, j; i < m && i != m && j != n;)
  {
    if (arr[i] > brr[j])
    {
      swap(arr[i], brr[j]);
      i++;
      // rearranging brr in sorted array
      //! sort(brr, brr+n); complexity: O(nlogn)... we will optimise it to O(n)
      for (int k = n - 1; k > 0; k--) // placing brr[0] int its corrected positiion throuh loop.
      { // traversing right to left
        //if smalled than or equal to brr[0] swap.
        //ex. 15,11,13,13,16
        // 15,11,13,13,16
        //13, 11, 13,15,16
        // 13, 11,13, 15, 16
        // 11,13 , 13,15,15

        // other example... 16,10,13,15,18,20
        // 15, 10, 13, 16,18, 20
        // 13, 10, 15, 16, 18, 20
        // 10, 13, 15, 16, 18 , 20
        if (brr[k] <= brr[0])
        {
          swap(brr[k], brr[0]);
        }
      }
    }
    else
      i++;
    cout << "a1: \n";
    for (int c = 0; c < m; c++)
      cout << arr[c] << " ";
    cout << "\nSecond Array: \n";
    for (int v = 0; v < n; v++)
      cout << brr[v] << " ";
    cout << "\narr index: " << i << endl;
    cout << "brr index: " << j << endl;
  }
}
int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.tie(NULL); //done to stop waiting of scanf/printf sync
  int ar1[] = {1, 5, 9, 10, 15, 20};
  int ar2[] = {2, 3, 8, 13};
  int m = sizeof(ar1) / sizeof(ar1[0]);
  int n = sizeof(ar2) / sizeof(ar2[0]);
  cout<<" step by step iterations .... \n";
  merge(ar1, ar2, m, n);

  cout << "After Merging nFirst Array: ";
  for (int i = 0; i < m; i++)
    cout << ar1[i] << " ";
  cout << "\nSecond Array: ";
  for (int i = 0; i < n; i++)
    cout << ar2[i] << " ";

  return 0;
}
////! APPROAH 2... GAP METHOD complexity... log2n*O(n) space O(n);
// ? no initution... only algo better than insertion sort method.
// tell interviewr if he ask to optimise after approah 2.
//! you cant think of this algorithm on the spot, becuase no intituion...or cant expaling why its working...
// just in case if he ask tell him a method like do exists.
/*

gap method... gap ke interval wale index ko swap karo if bada
you can also jump from one array to other if gap allows to jump.. like if gapped index is more than m than gap would lie in 2ns arraay
but if it crosses n then update gap and traverse frrom beginnig of m
gap=n/2... next time = gap/2.. next time= gap/2.while(gap!=0)
*/
//! BUT....
//what the initution of this algorithm , 
//why its working this way? if no idea how will you dicuss the approach... quadratic time solution is fine.