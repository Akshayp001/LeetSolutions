#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s, int ind, vector<int>& dp) {
        int n = s.length();
        
        if (dp[ind]!=-1) return dp[ind];

        if (ind==n) return dp[ind]=1;
        if (s[ind]=='0') return dp[ind]=0;

        int ways = solve(s, ind+1, dp);

        if (ind<n-1 && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6')))
            ways += solve(s,ind+2,dp);

        return dp[ind]=ways;
    }

    int numDecodings(string s) {
        if (s.empty() || s[0]=='0') return 0;
        vector<int> dp(s.length()+1, -1);
        return solve(s,0,dp);
    }
};
