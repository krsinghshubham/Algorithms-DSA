//link: https://www.geeksforgeeks.org/quick-sort/
/* C++ implementation QuickSort using Lomuto's partition 
Scheme.*/
// hoarse is difficult to implement, 
// compared to merge sortquick sort is not good for large data sets, and on low data sets time differnce is neglible.
// although merger sort usees extra space to store auxillary arrays while quick sort doesn't.
#include <cstdlib>
#include <iostream>
using namespace std;
void printArray(int arr[], int size);

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition(int arr[], int low, int high)
{

    int i = low - 1; // to find postion of pivot
    int pivot = arr[high];
    for (int j = low; j <= high - 1; j++)
    { // this to itereate elements upto pivoted element which is high in this case
        if (arr[j] <= pivot)
        {
            i++;                  // need to incremet first then swap.
            swap(arr[i], arr[j]); //

        } // not ith position , but upto that each one is shorter than pivot
    }
    swap(arr[i + 1], arr[high]); // sandwiched at ith positon
    // so return ith postioin which is i+1
    return i + 1;
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int random_partion(int arr[], int low, int high)
{

    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = random_partion(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    cout << endl
         << typeid(arr).name() << endl;

    return 0;
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}