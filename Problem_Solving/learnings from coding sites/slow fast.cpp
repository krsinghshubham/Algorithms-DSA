// https://leetcode.com/problems/happy-number/
/* test cases:
Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/
#include<iostream>
#include<set>
using namespace std;
class Solution {
public:
    bool isHappy(int n)
    {
        int slow, fast;
        slow=fast=n;
        do
        {
            slow=ss(slow);
            fast=ss(ss(fast)); // 1 ane pe next square bhi 1 and equal hoga
        } while (slow!=fast);
        return(slow==1);
    }
    int ss(int n)
    {
        int sum=0;
        while (n>0)
        {
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }

};

// another approah: above one is more efficient as thats consuming less space

class Solution {
public:
    int sumOfSquares(int n){
        int sum=0;
        while(n>0){
            int t = n%10;
            sum+= (t*t);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> s;
        while(n!=1){
            int temp = sumOfSquares(n);
            if(s.find(temp)==s.end()) s.insert(temp);
            else return false;
            n = temp;
        }
        return true;
    }
};