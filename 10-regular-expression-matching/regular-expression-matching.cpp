class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        if (i == s.size() && j == p.size()) return true;
        if (j == p.size()) return false;
        if (dp[i][j] != -1) return dp[i][j];

        bool match = (i<s.size() && (s[i]==p[j] || p[j]=='.'));

        if (j+1<p.size() && p[j+1]=='*') {
            bool check = solve(s,p,i,j+2,dp) || (match && solve(s,p,i+1,j,dp));
            return dp[i][j] = check;
        } else {
            bool check = match && solve(s,p,i+1,j+1,dp);
            return dp[i][j] = check;
        }
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0, dp);
    }
};
