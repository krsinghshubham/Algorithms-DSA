
// EUCLID's ALGORITHM FOR DOING GCD.

class Solution
{
public:
    int gcd_using_euclid(int divisor, int dividend)
    {
        if (dividend % divisor == 0)
            return divisor;
        return gcd_using_euclid(dividend % divisor, divisor);
    }
    bool hasGroupsSizeX(vector<int> &deck)
    {
        // store a map with element and count.
        // (FAILED LOGIC, [1,1,1,1,2,2,2,2,2,2](OUTPUT SHOULD BE TRUE.) iterate map, keep track of minimum count,now check with all count and if the count varies and its not a multiple of min_count return false.
        // correct logic is the gcd of the numbers should be greater than 2.
        // finally return true;
        unordered_map<int, int> ump;
        for (auto x : deck)
            ump[x]++;
        // 1st count should be gcd with zero.
        int gcd = 0;
        for (auto i : ump)
        {
            gcd = gcd_using_euclid(i.second, gcd); // gcd as first parameter will give divide/zero error.
        }
        if (gcd < 2)
            return false;

        return true;
    }
};