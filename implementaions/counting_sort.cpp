//problem link: https://leetcode.com/problems/sort-colors/
/*
although its totally my implementation, gfg link is for refrence: 

*/
// learning: Counting Sort.
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
1. Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K.
2. It is not a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data.
3. It is often used as a sub-routine to another sorting algorithm like radix sort.
4. Counting sort uses a partial hashing to count the occurrence of the data object in O(1).
5. Counting sort can be extended to work for negative inputs also.

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//1. store the count of elements in count array (r-l), size be no of elements in range and intialize zero
//2. coummulate the count array
//3. make an output array , size as originala array
//4. find postion of elemeent for orignal array by -1 and assign in output array
#define PI 3.1415926535897932384626
void counting_sort(vector<int> arr, int l, int r) // implementing based on vector because of leetcode dominance.
{
    vector<int> count(r - l + 1, 0); // ,0 to initalize with all zero
    int n = arr.size();
    for (auto x : arr)
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
    for (auto x = arr.begin(); x != arr.end(); x++) // note we are traversing mums array not count 
    {
        count[*x]--; //1st(because 0 indexing ) decrementing the value of count that if same element occured it gets a new value 
        // after decremting count array will store the correct postion of element wrt 0 indexing in new output arrray.

        output[count[*x]] = *x; // storing element at correct position in output array.
    }
    /*
     For Stable algorithm  
    for (i = sizeof(arr)-1; i>=0; --i)  
    {  
        output[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }  
      
    For Logic : See implementation 
    */
    // for (auto x : output)
    //     cout << x << " "; // although otuput contains same element as required but we requrire changes in the given array itself.
         vector<int>::iterator it=arr.begin();
    for(auto x=output.begin();x!=output.end();x++,it++){
        *it=*x; // replacing the contents of output into given array because leetcode verifies it by 
        // checking elemetns of the original array alone and not by comparing the output on the screen.
        //atleast in void functions. thats what i coformed, they do this to avoid presentation error.
    }
    for(auto k: arr)
    cout<<k<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l = 0, r = 9; // least and max value for range.
    vector<int> arr = {1, 4, 1, 2, 7, 5, 2};

    counting_sort(arr, l, r);

    return 0;
}
