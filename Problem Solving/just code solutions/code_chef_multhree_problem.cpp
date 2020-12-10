// C++ program to reverse a subarray arr[0..k-1]
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Driver program
int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;
        // vector<long int> arr; // storing speeds of car.
        // while (n--)
        // {
        //     long int x;
        //     cin >> x;
        //     arr.push_back(x);
        // }
                ll arr[n];

        for(int i=0;i<n;i++)
        cin>>arr[i];
        // for(auto x: arr)
        // cout<<x<<" ";
        // cout<<endl;
        int count = 1;
        for (int i=1;i<n;i++)
        {   
            if(arr[i]<arr[i-1])
            count++;

        }
        cout<<count<<endl;
        
    }

    return 0;
}

// // C++ program to reverse a subarray arr[0..k-1]
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// // Driver program
// int main()
// {
//     int tc;
//     cin >> tc;

//     while (tc--)
//     {
//         int n;
//         cin >> n;
//         vector<ll> arr; // storing speeds of car.
//         while (n--)
//         {
//             ll x;
//             cin >> x;
//             arr.push_back(x);
//         }
//         // for(auto x: arr)
//         // cout<<x<<" ";
//         // cout<<endl;
//         int count = 1;
//         for (auto it = arr.begin()+1;it != arr.end(); it++)
//         {   
//             if(*it<*(it-1))
//             count++;

//         }
//         cout<<count<<endl;
//     }

//     return 0;
// }

