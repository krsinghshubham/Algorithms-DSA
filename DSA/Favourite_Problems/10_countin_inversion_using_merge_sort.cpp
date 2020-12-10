
// C++ program to Count Inversions in an array using Merge Sort
//Problem and tutorial: https://www.geeksforgeeks.org/counting-inversions/

#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int left, int mid, int right)
{
    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[n];
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid;  /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            /* this is tricky -- see above 
			explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray 
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray 
(if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort(int arr[], int left, int right)
{
    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[n];
    int mid, inv_count = 0;
    if (right > left)
    {

        mid = (right + left) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, left, mid + 1, right);
    }
    return inv_count;
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, 0, n - 1);
    cout << " Number of inversions are " << ans;
    return 0;
}
