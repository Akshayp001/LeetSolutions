#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i = 0; i < n; i++)  dp[0][i] = matrix[0][i];
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int best = INT_MAX;
                for(int k = 0; k < n; k++) {
                    if(k != j) {
                        best = min(best, dp[i - 1][k]);
                    }
                }
                dp[i][j] = matrix[i][j] + best;
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        
        return ans;
    }
};
