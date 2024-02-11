class Solution {
public:
    int m, n;
    int solve(int x, int y, int z, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (y<0 || y>=m || z<0 || z>=m) return INT_MIN;
        if (x==n-1) return (y==z) ? grid[x][y]:grid[x][y]+grid[x][z];

        if (dp[x][y][z]!=-1) return dp[x][y][z];
        int maxi = INT_MIN;
        for (int i=-1;i<=1;i++) {
            for (int j=-1;j<=1;j++) {
                int temp =(y==z)?grid[x][y]:grid[x][y]+grid[x][z];
                temp += solve(x+1,y+i,z+j,grid,dp);
                maxi = max(maxi,temp);
            }
        }
        return dp[x][y][z]=maxi; 
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid[0].size();
        n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return max(0, solve(0,0,m-1,grid,dp)); 
    }
};
