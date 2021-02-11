//problem link:https://leetcode.com/problems/powx-n/submissions/
// Reference linK:
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); //done to stop waiting of scanf/printf sync
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:
*Naive:
* Time: O(n), Space: O()

*Optimized:
* Time: O(logN),sayad Space: O(logn)
if n is negative we have to make it positve:
        but since -ve of INT_MIN will give integer overflow for int, we have to use long long init.
        will use binary exponentiation.
        2^17 ,  n=17, base=2
        result=1;
        while(n!=0) 
        if(n%2) // odd
        result=result*base, n--,  r=2; base=2, n=16
        else
        base=base*base, n=n/2; base=4, n=8

*/
double myPow(double x, int n)
{
    bool negFlag = false;
    long long power;
    if (n < 0)
    {
        negFlag = true;
        power = abs(n); // to store abs of INT_MIN
    }
    else
    {
        power = n;
    }
    long double ans = 1;
    long double base = x;
    while (power)
    {
        if (power % 2) // odd case
        {
            ans *= base;
            power--;
        }
        else
        {
            base *= base;
            power = power / 2;
        }
    }
    if (negFlag)
        return 1 / ans;
    return ans;
}
int main()
{
    FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE;
    double x;
    int n;
    cin >> x >> n;
    printf("%f", myPow(x, n));
    cout << endl; //! IMP: %f in printf is printing trailing zeros too.
                  //! while cout is turnacating the trailing zeros.
    cout << myPow(x, n);

    return 0;
}
