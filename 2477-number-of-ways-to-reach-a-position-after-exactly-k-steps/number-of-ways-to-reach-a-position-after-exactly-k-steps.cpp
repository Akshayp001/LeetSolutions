class Solution {
public:
    const int M = 1e9 + 7;

    int solve(int ind, int end, int k, vector<vector<int>> &dp) {
        if (k == 0) {
            if (ind == end) return 1;
            else return 0;
        }
        if (dp[ind+999][k] != -1) return dp[999+ind][k];

        return dp[ind+999][k]=((solve(ind-1,end,k-1,dp) % M) + (solve(ind+1,end,k-1,dp) % M)) % M; 
    }

    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000, vector<int>(k + 1, -1));
        return solve(startPos, endPos, k, dp);
    }
};
