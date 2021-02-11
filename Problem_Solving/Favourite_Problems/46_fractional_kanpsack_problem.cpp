//problem link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
// Reference linK:
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
same greedy concept.
* Time: O(NlogN), Space: O(1)
*/
// C/C++ program to solve fractional Knapsack Problem
#include <bits/stdc++.h>

using namespace std;

struct Item {
	int value, weight;
	Item(int value, int weight)
	{
	this->value=value;
	this->weight=weight;
	}
};

double fractionalKnapsack(int W, Item arr[], int n)
{
    // will take the items first which will give more profit per wight . 
    sort(arr, arr+n, [](Item I1, Item I2){
        return ((double)I1.value/(double)I1.weight)>=((double)I2.value/(double)I2.weight);
    });
    double profit=0;
    for(int i=0;i<n;i++)
    {
     if(arr[i].weight<W)
     {
         profit+=arr[i].value;
         W-=arr[i].weight;
     }
     else
     {
         //int n=W%arr[i].weight;
         profit+=(double)W*(double)((arr[i].value)/(arr[i].weight));
         break;
     }
    }
    return profit;
}

int main()
{
	int W = 50; // Weight of knapsack
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Maximum value we can obtain = "
		<< fractionalKnapsack(W, arr, n);
	return 0;
}

