// C++ program to sort an array
// with 0, 1 and 2 in a single pass
// link for imp: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
// and: https://www.youtube.com/watch?v=oaVa-9wmpns
// problem: https://leetcode.com/problems/sort-colors/

// this is only for 0,1 ,2 but can be used in quick sort variationc called 3 way qucik sort
#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int arr_size)
{
    /*algo:
    low... left of it will be 0
    right... of will it be 2
    mid... in between all be 1
    step 1: fix low, mid at start,high at end
    2: if zero swap with mid, low++, mid++
    3. if 1:, then mid++,
    4.. if 2 :swapa with high, high--;

    */
    int low = 0;
    int high = arr_size - 1;
    int mid = low;
    while (mid <= high)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[low], a[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(a[mid], a[high]);
            high--;
            // we are not incementing mid at this step because we dont know the content of a[high], if its zero then in next step
            // we have to transfer it correct place.
            break;
        }
    }
}

void printArray(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, n);

    cout << "array after segregation ";

    printArray(arr, n);

    return 0;
}

// another approach
// this can be done quickly by following:
// step 1: store count of zeros, ones and two
// while(zeros--) cout<< 0; 
// while (ones--) cout<< 1;
// while(twos--) cout<< 2;
// only extra space will be taken, run time same.
