//problem link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// Reference linK: Self Intitution and: https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0pmWCl2nepwGDO05a0-7EfJ&index=3&ab_channel=takeUforward
// learning: Greedy time complexity can be worse than Nlogn. 

/*
Algorithm:
sort my profit, make an array to track free slots. 
put the job in free slot. 
* Time: O(nlogN+ n*m= N^2 (in worst)), Space: O(1)
*/

pair<int, int> JobScheduling(Job arr[], int n)
{
  sort(arr, arr + n, [](Job a, Job b) {
    return a.profit > b.profit;
  });

  int days[n + 1]; // to keep free days/slots.
  for (int i = 0; i <= n; i++)
    days[i] = -1;
  int noj = 0, profit = 0;
  for (int i = 0; i < n; i++)
  {
    int index = arr[i].dead;
    while (days[index] != -1) // this can go at max to N.
      index--;
    if (index > 0)
    {
      profit += arr[i].profit; // arr[i] and not arr[index]
      days[index] = 1;
      noj++;
    }
  }
  return make_pair(noj, profit);
}