//problem link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// tutorial linK: striver's is not good, my own code is better.
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
Algorithm:  GREEDY
sort on the basis of end time in decreasing order(we can do a logic for increasing one too), if end time is same, then the one whose start time is more will come first coz that will take less window. 
then
(note we are traversing from backwards here ...)
1st meeting always takes place and current =1st meet, from 2nd meeting onwards if its start time is more than current.end time, it will take place, count++, current=i;

* NlognN for sort, N for traversal , overall Nlogn. 
* Time: O(nlogn), Space: O(1)
*/
#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);


int maxMeetings(int start[], int end[], int n) {
    /*
    start: 0,1,3,5,5,8
    end:    2,4,6,7,9,9
    8   5   5   0   3   1
    9   9   7   6   4   2
    1   3   0   5   5   7
    2   4   6   7   9   9

    */
    if(n==1)
    return 1;
    vector<pair<int,int>>times;
    for(int i=0;i<n;i++)
    {
        times.push_back(pair<int,int>(start[i], end[i]));
    }
    sort(times.begin(),times.end(), [](pair<int,int>s, pair<int,int>f)
    {
        return s.second>f.second || s.second==f.second && s.first>f.first;
    });
    // for(auto x: times)
    // {
    //     cout<<x.first<<" ";
    // }
    // cout<<endl;
    //  for(auto x: times)
    // {
   
    //     cout<<x.second<<" ";
    // }
    // cout<<endl;
    int count=1,current=n-1;
    for(int i=n-2;i>=0;i--)
    {
        if(times[i].first>times[current].second) //  we are not assigning a meeting whose end time is x and next meeting's start time is also x, instead it should be lesser.
        {
            count++;
            current=i;
        }
    }
    // cout<<"\n ans is: "<<count;
    return count;
}




// 92  48  74  67  99  61  54  62  30  87  59  84  72  88  64  87  54  87  33  54  21  41  43  48  45  8  3  24  5  3  
// 150 150 148 145 139 137 131 126 126 118 117 115 109 108 104 102 99  96  93  82  73  68  67  60  59  50 49 27  7  6 
// 4
int main() {
    int t=1;
 
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout <<endl<< ans << endl;
    }
    return 0;
}// } Driver Code Ends
