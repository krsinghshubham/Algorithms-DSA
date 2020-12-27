//* WAITING FOR THE VIDEO TUTORIAL FROM STRIVER.
//problem link: https://www.interviewbit.com/problems/subarray-with-given-xor/#
// tutorial linK: https://www.youtube.com/watch?v=lO9R5CaGRPY&list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_&index=5&ab_channel=takeUforward
// learning: 
#include <bits/stdc++.h>   
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   //done to stop waiting of scanf/printf sync
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:

* Time: O(N log(n)), Space: O(), log(n) because of unordered_map, we are using unordered_map, so ideally its 1, overall O(N*1) but unordered_map in worst case gives complications.
*/ 


// O(n) time complexity.
#include <bits/stdc++.h>
using namespace std;

// Returns count of subarrays of arr with XOR
// value equals to target
int subarrayXor(int arr[], int size, int target)
{
    /*
    subarray which xorred to target ... will give as value = target. 
    3,56,67,4,46,6
      _______     ... suppose this is ans.
      then 
    preSum till 3 ^ target = xorPresum till 4. 
    preSum till 3= xorPresum till 4 ^ target. 
      so for all such combinations we will get no of subArrays. 
    Now again we will check frequency and not just increment by 1. because  left.. (here its preSum till 3) can be something else subarray too.... 
    so thats the reason. VIDEO TIME STAMP TO UNDERSTANS THIS IS: 08:05;
    */
   int xorr=0;
   int count=0;
   unordered_map<int,int>Freqhashmap;
   for(int i=0;i<size;i++)
   {
     xorr^=arr[i];
     if(xorr==target) // if xorr itself equals then its ans. 
     count++; 
    if(Freqhashmap.find(xorr^target)!=Freqhashmap.end()) // we found a ans subarray because kind of left part exist and we can check that by checking prexorr in frequency array.
    count+=Freqhashmap[xorr^target]; // such preXOR exist, so we can get such sub arrays.  VIDEO TIME STAMP TO UNDERSTANS THIS IS: 08:05;
         
    Freqhashmap[xorr]++; //STORE THE PRExOR and update the freqency count.
   }
   return count;
}

// Driver program to test above function
int main()
{
	int arr[] = { 4, 2, 2, 6, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = 6;

	cout << "Number of subarrays having given XOR is "
		<< subarrayXor(arr, n, m);
	return 0;
}
