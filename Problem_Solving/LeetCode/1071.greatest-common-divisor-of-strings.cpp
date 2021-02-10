class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // implement gcd in form of strings.
        // failed:intital intuition: if its a gcd sting then smaller stirng should be at first index of bigger string.//"ABABAB", str2 = "ABAB", output= "AB"
        //GCD:
        if (str1.length() < str2.length()) // switch smaller string at 2nd pos
            return gcdOfStrings(str2, str1);
        if (str2.empty())
            return str1;                           // gcd(5,0)=5
        if (str1.substr(0, str2.length()) != str2) // if smaller string is empty or not at index of bigger string. returnn false.
            return "";
        return gcdOfStrings(str1.substr(str2.size()), str2); // we are here if str2 is a part of str1, now we need to check remaining part of str1.// "ABABAB", str2 = "ABAB", output= "AB"
    }
};

// euclid's ALGORITHM FOR DOING GCD.

//     int gcd_using_euclid(int divisor,int dividend)
//     {
//         if(dividend%divisor==0) return divisor;
//         return gcd_using_euclid(dividend%divisor,divisor);
//     }
