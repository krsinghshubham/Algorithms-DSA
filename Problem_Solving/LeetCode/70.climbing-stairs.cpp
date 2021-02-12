// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==1 || n==2)
//             return n;
//         return climbStairs(n-1)+climbStairs(n-2);
//     }
// }; //space takin. 
class Solution {
public:
    int climbStairs(int n) {
        if(n<3)
            return n;
       int arr[n+1];
        arr[0]=0;
        arr[1]=1;
        arr[2]=2;
        for(int i=3;i<=n;i++)
            arr[i]=arr[i-1]+arr[i-2];
        return arr[n];
    }
}; 