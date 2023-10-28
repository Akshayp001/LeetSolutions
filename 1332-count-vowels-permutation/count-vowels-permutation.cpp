class Solution {
public:
    int countVowelPermutation(int n) {
        // a e i o u
        // 1 2 3 4 5
        long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(6, 0));
        for (int i = 1; i < 6; i++) {
            dp[1][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            dp[i + 1][1] = (dp[i][2] + dp[i][3] + dp[i][5]) % MOD;
            dp[i + 1][2] = (dp[i][1] + dp[i][3]) % MOD;
            dp[i + 1][3] = (dp[i][2] + dp[i][4]) % MOD;
            dp[i + 1][4] = (dp[i][3]) % MOD; 
            dp[i + 1][5] = (dp[i][3] + dp[i][4]) % MOD;
        }
        long long ans = (dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5]) % MOD;
        return ans;
    }
};
