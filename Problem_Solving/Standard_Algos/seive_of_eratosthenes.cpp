//problem link: https://leetcode.com/problems/count-primes/
// Reference linK:
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.tie(NULL); //done to stop waiting of scanf/printf sync
    int n;
    cin >> n;
    if(n<=2)
    return 0; // becuase array will go out of bound for n=2,n=1 
                            //!and we cant declare aray of size 0 and less than 1
    int primes[n];

    for (int i = 0; i*i < n; i++) // all ements initalize to one
    {
        primes[i] = 1;

        
    }
    primes[0] = primes[1] = 0; // these are neither primes nor composte
    for (int i = 2; i *i<= n; i++)
    {
        if (primes[i] == 1)
            for (int k = i * i, j = i; k < n; k = i * ++j) // from i square, till all multiples of i till n
            {
                primes[k] = 0; // multiples of n;
            }
        // if ((i + 1) * (i + 1) > n)
        //     break;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (primes[i] == 1)
        {
            cout << i << " ";
            count++;
        }
    }

    cout << "\nno of primes is: " << count;
    return 0;
}
//! COMPLEXITY: nLog(logn)+n;