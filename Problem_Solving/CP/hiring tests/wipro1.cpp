
#include <iostream>
#include<vector>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int>v1;
    v1.push_back(arr[0]);
    int min=arr[0]; 
    for(int i=1;i<n;i++)
    {
        if(arr[i]<min)
        {
        v1.push_back(arr[i]);
        min=arr[i];
        }
    }
    
    vector<int>::iterator it;
    for (it = v1.begin(); it !=v1.end(); it++)
        cout << *it<<" ";
  return 0;
}

