class Solution {
public:
    int ways(int n, int k, int t, vector<vector<int>>& dp){
        const int MOD = 1000000007;
        if(n==0 && t==0) return 1;
        if(n<=0 || t<=0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];

        int w = 0;
        for(int i=1; i<=k;i++){
            if(t-i>= 0) {
                w=(w+ways(n-1,k,t-i,dp))%MOD;
            }
        }
        return dp[n][t] = w;
        
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
        return ways(n, k, target, dp); 
    }
};
