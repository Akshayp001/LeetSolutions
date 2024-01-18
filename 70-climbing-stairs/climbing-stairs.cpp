class Solution {
public:
//     int solve(int stair, vector<int> &dp) {
//   // Base case
//   if (stair == 0 || stair == 1)
//     return 1;

//   if (dp[stair] != -1){

//     return dp[stair];
//   }

//   return dp[stair] = solve(stair - 1, dp) + solve(stair - 2, dp);
// }
// int climbStairs(int nStairs) {

//   vector<int> dp(nStairs+1, -1);
//   int ways = solve(nStairs, dp);
//   return ways;
// }
    // int ways(int n){
    //     int a=0;
    //     int b=1;
    //     int ans;
    //     if(n==1 || n==0) return n;
    //     for(int i=2;i<=n;i++){
    //         ans = a+b;
    //         a=b;
    //         b=ans;
    //     }
    //     return ans;
    // }
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        if(n==0 || n==1) return a;
        for(int i=0;i<n-1;i++){
            int sum = a+b;
            a = b;
            b = sum;
        }
        return b;
    }
};


