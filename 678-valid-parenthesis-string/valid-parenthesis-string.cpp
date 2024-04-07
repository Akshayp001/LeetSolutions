#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int scr, string &s, vector<unordered_map<int, int>>& dp) {
        if (i >= s.length()) return scr == 0;
        
        if (dp[i].find(scr) != dp[i].end())  return dp[i][scr];
        if(scr<0) return false;

        if (s[i] == '(') {
            return dp[i][scr]=solve(i+1,scr+1,s,dp);
        } else if (s[i] == ')') {
            return dp[i][scr]=solve(i+1,scr-1,s,dp);
        } else {
            return dp[i][scr]=solve(i+1,scr+1,s,dp) || solve(i+1,scr-1,s,dp) || solve(i +1,scr,s,dp);
        }
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<unordered_map<int, int>> dp(n + 1);
        return solve(0, 0, s, dp);
    }
};
