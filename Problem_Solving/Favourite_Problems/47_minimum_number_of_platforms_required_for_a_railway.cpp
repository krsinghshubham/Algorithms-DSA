//problem link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// Reference linK: greedy. https://www.youtube.com/watch?v=dxVcMDI7vyI&list=PLgUwDviBIf0pmWCl2nepwGDO05a0-7EfJ&index=2&ab_channel=takeUforward
// learning:
//! SOMETIMES WHILE LOOP KEEP THINGS SIMPLER THAN FOR LOOP, EXAMPLE IS HERE.
#include <algorithm>
#include <iostream>
using namespace std;
/*
Algorithm:
* N(lognN) for sort, N for traversal , overall Nlogn. 
* Time: O(nlogn), Space: O(1)
*/
/*
int findPlatform(int arr[], int dep[], int n)
{
	// arrival and departure need to be on diffrenet platforms
	//if arrival time is less than departure time then we need to increase platform. 
	// sort by deaprture time, 1st will always consider. 
	// while arrival time is less than departure time of current train, increament overlap, and take max of all. 
    sort(arr,arr+n); // we need not to sort arr, and departure together, since platform occupancy is based on arr/dep. 
    sort(dep,dep+n);
    int overlap=1, currentOverlap=1;
    // two pointer appraoch.
    int current=0; // 1st train
    for(int i=1;i<n;i++)
    {
        currentOverlap=1;
        while(arr[i]<dep[current])
        {
            currentOverlap++;
            i++;
            
        }
        overlap=max(overlap, currentOverlap);
        if(currentOverlap>1) //! THINGS GET COMPLICATED WITH FOR LOOP. // no this kind of extra work if while loop would have been implemented. 
        i--;
        else
        current=i;
    }
return overlap;
}
*/
int findPlatform(int arr[], int dep[], int n)
{

  // arrival and departure need to be on different platforms
  //if arrival time is less than departure time then we need to increase platform.
  // sort by departure time, 1st will always consider.
  // while arrival time is less than departure time of current train, increment overlap, and take max of all.
  sort(arr, arr + n); // we need not to sort arr, and departure together, since platform occupancy is based on arr/dep.
  sort(dep, dep + n);
  int overlap = 1, currentOverlap = 1;
  // two pointer approach.
  int current = 0; // 1st train
  for (int i = 1; i < n; i++)
  {
    currentOverlap = 1;
    while (arr[i] < dep[current])
    {
      currentOverlap++;
      i++;
    }
    overlap = max(overlap, currentOverlap);
    if (currentOverlap > 1)
      i--;
    else
      current = i;
  }
  return overlap;
}

int main()
{
  int arr[] = {900, 940, 950, 1100, 1500, 1800};
  int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Minimum Number of Platforms Required = "
       << findPlatform(arr, dep, n);
  return 0;
}
