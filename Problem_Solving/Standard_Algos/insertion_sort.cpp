//problem link:https://www.geeksforgeeks.org/insertion-sort/
// learning:
// Time Complexity: O(n*2)
// Auxiliary Space: O(1)
// Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order.
// And it takes minimum time (Order of n) when elements are already sorted.
// Algorithmic Paradigm: Incremental Approach
// Sorting In Place: Yes
// Stable: Yes

// Uses: Insertion sort is used when number of elements is small.
// It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
void insertionSort(int arr[], int n)
{ // pick an element and move to its correct postion in left, when reached rightmost index... boom its sorted.
    int i, j, key;
    for (i = 1; i < n; i++) //start with index 1, to comapre
    {
        key = arr[i];                  // storing element
        j = i - 1;                     //start with adjacent left element.
        while (j >= 0 && arr[j] > key) // compare left elemnt is key
        {
            arr[j + 1] = arr[j]; // swaping to the right.... to make space for original location of key.
            j--;
        }
        arr[j + 1] = key; // to easy understand j is -1 in few case...
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.tie(NULL); //usuall when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.

    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
