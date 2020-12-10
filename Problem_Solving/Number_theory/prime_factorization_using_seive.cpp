//problem link:
// tutorial linK: https://www.youtube.com/watch?v=DQJfvz2Dhss&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=10&ab_channel=CodeNCode
// learning: O(sqrt(n)) method is mentioned in notebook
//! this gives us  O(logn )complelxity. , therory in notebook
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
int SPF[100001];       // smallest prime factors
void calculateSPF()
{
    memset(SPF, -1, sizeof(SPF));
    SPF[1] = 1;
    for (int i = 2; i < 100001; i++)
    {
        if (SPF[i] == -1)
        {
            for (int j = i + i; j < 100001; j += i)
            {if(SPF[j]==-1)
                SPF[j] = i;
            }
        }
    }
    //! uptill here precoumpuation done .... complexity.. O(logn)
    // for(int i=1;i<70;i++)
    // cout<<i<<"="<<SPF[i]<<" ";
}
void calculatePrimeFactors(int n)
{ //! time complexity for this function is O(log N)
    while (n != 1 || SPF[n] != -1)
    {
        if (SPF[n] == -1)
        {
            cout << n  ;
            break;
        }
        else
        {
            cout<<SPF[n]<<"*";
            n/=SPF[n];
        }
        if (SPF[n] == -1)
        {
            cout << n;
            break;
        }
        
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.tie(NULL); //usuall when cin then it waits for cout and the it syncs,,, these 3 flag stops the sync and tell compiler i wont use scanf , printf after/before cout... so u need not to waste time and move ahead.

    calculateSPF();
    //! initialize test case after here... so that precomputation is done.
    int n;
    cin >> n;
    calculatePrimeFactors(n);

    return 0;
}
