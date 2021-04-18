/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n)
    {
     if(n<=2)
         return 0;
    int primes[n] ;
    
      for (int i = 0; i < n; i++) // all ements initalize to one
    {
         primes[i] =1;
    }
    primes[0] = primes[1] = 0; // these are neither primes nor composte
    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == 1)
            for (int k = i * i, j = i; k < n; k = i * ++j) // from i square, till all multiples of i till n
            {
                primes[k] = 0; // multiples of n;
            }
        if ((i + 1) * (i + 1) > n)
            break;
    }
    int count =0;
    for (int i = 0; i < n; i++)
    {   if(primes[i]==1)
        count ++;
        
    }

return count;
    }
};
// @lc code=end

