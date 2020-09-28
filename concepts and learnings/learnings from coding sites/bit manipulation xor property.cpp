// https://leetcode.com/problems/single-number/
/* Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

class Solution 
{
public:
        int singleNumber(vector<int>& nums) 
        { 
        
            int x=0;
            for(int i=0;i<nums.size();i++)
           x=x ^ nums[i];
           
                return x;
        } 
};
/* If we take XOR of zero and some bit, it will return that bit
a \oplus 0 = aa⊕0=a
If we take XOR of two same bits, it will return 0
a \oplus a = 0a⊕a=0
a \oplus b \oplus a = (a \oplus a) \oplus b = 0 \oplus b = ba⊕b⊕a=(a⊕a)⊕b=0⊕b=b
4,0=4
4,1=4,1
4,1,2=4,1,2
4,1,2,1=4,2,0=4,2
4,2,2=4,0=4
ans=4
*/

