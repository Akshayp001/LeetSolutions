#include <vector>

class Solution {
    int m;
    int n;
public:
    int mod = 1e9 + 7;

    vector<vector<vector<int>>> dp;

    int solve(int x, int y, int moves) {
        if (x >= m || x < 0 || y >= n || y < 0) return 1;
        if (moves == 0) return 0;
        if (dp[x][y][moves] != -1) return dp[x][y][moves];
        

        int ans = 0;
        ans=(ans+solve(x + 1,y,moves-1))%mod;
        ans=(ans+solve(x - 1,y,moves-1))%mod;
        ans=(ans+solve(x, y +1,moves-1))%mod;
        ans=(ans+solve(x, y -1,moves-1))%mod;

        dp[x][y][moves] = ans;
        return ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        dp.assign(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        return solve(startRow, startColumn, maxMove);
    }
};
