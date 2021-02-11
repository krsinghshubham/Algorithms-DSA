//problem link: https://leetcode.com/problems/sort-colors/
// Reference : https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2&t=110s&ab_channel=takeUforward
// * learning: Counting Sort and DUTCH NATIONAL ALGORITHM
/*
coutning sort is good for short range arrays 
**
time complexity is o(n)
precisely o(n*R) where r is range, so for large range this is not efficent.
**
also it is good for short range integers only as in this question because r is difference between 
min and max element, so if only two elements and then they are 1, 1000000 , then range is 999999 which is not good.
**
Counting sort has better time complexity but worse space complexity. 
**
So if you have very large sets it really depends on what is more important to you... memory consumption or CPU consumption.
and what if elements are not integers but strings, how will you implement counting sort.
Points to be noted:
1. Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. 
    Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K.
2. It is not a comparison based sorting. Its running time complexity is O(n) with space proportional to the range of data.
3. It is often used as a sub-routine to another sorting algorithm like radix sort.
4. Counting sort uses a partial hashing to count the occurrence of the data object in O(1).
5. Counting sort can be extended to work for negative inputs also.
*/

// appproach 1 least efficient.
// runtime: 8ms
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626
class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    for (auto x : nums)
      cout << x;
  }
};


// appproach 2 using counting sort.
// Reference : https://www.youtube.com/watch?v=7zuGmKfUt7s&ab_channel=GeeksforGeeks
//runtime: 8ms
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int l = 0, r = 2;
    vector<int> count(r - l + 1, 0);
    int n = nums.size();
    for (auto x : nums)  
    
    {
      ++count[x]; // no of occurrences hashed into count.
    }
    for (auto it = count.begin() + 1; it != count.end(); it++)
    {
      *it += *(it - 1); // coummulating the count array
    }

    // for (auto x : count)
    //     cout << x << " "; // checking count array
    vector<int> output(n); // to store the result for printing.
    for (auto x = nums.begin(); x != nums.end(); x++)
    {
      count[*x]--; //1st decrementing the value of count that if same element occured it gets a new value.

      output[count[*x]] = *x; // passing value of original array into correct position in output.
    }
    vector<int>::iterator it = nums.begin();
    for (auto x = output.begin(); x != output.end(); x++, it++)
    {
      *it = *x; // replacing the contents of output into given array because leetcode verifies it by
                // checking elemetns of the original array alone and not by comparing the output on the screen.
                //atleast in void functions. thats what i coformed, they do this to avoid presentation error.
    }
    for (auto x : nums)
      cout << x;
  }
};
int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int l = 0, r = 2; // least and max value for range.
  vector<int> arr = {2, 0, 2, 1, 1, 0};
  Solution obj;
  obj.sortColors(arr);

  return 0;
}

// approach 3 using dutch national algo.
// C++ program to sort an array
// with 0, 1 and 2 in a single pass
// link for imp: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
// and: https://www.youtube.com/watch?v=oaVa-9wmpns
// problem: https://leetcode.com/problems/sort-colors/
// runtime 0 sec, 
// space: constant.
// * this is only for 0,1 ,2 but can be used in quick sort variationc called 3 way qucik sort
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
    4.. if 2 :swap with high, high--;

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
            // we are not incrementing mid at this step because we dont know the content of a[high], if its zero then in next step
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

// this can be done quickly by following:simpletst version of counting sort
// step 1: store count of zeros, ones and two
// while(zeros--) cout<< 0; 
// while (ones--) cout<< 1;
// while(twos--) cout<< 2;
// only extra space will be taken, run time same.
