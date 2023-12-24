class Solution {
public:
    int solve(string s, string t, int i, int j, int cnt, vector<vector<int>>& dp) {
        if (cnt == t.length()) {
            return dp[i][j] = 1;
        }
        if (i == s.length() || j == t.length()) {
            return dp[i][j] = 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int val = 0;
        if (s[i] == t[j]) {
            val = solve(s, t, i + 1, j + 1, cnt + 1, dp) + solve(s, t, i + 1, j, cnt, dp);
        } else {
            val = solve(s, t, i + 1, j, cnt, dp);
        }
        return dp[i][j] = val;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
        return solve(s, t, 0, 0, 0, dp);
    }
};
