class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<int> nConnectectComps(5,0);
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int conn=0;
                if(grid[i][j]==0) continue;
                if(i-1>=0 && grid[i-1][j]==1) conn++;
                if(i+1<n && grid[i+1][j]==1) conn++;
                if(j-1>=0 && grid[i][j-1]==1) conn++;
                if(j+1<m && grid[i][j+1]==1) conn++;
                nConnectectComps[conn]++;
            }  
        }
        int ans=0;
        for(int i=0;i<=4;i++) ans+=nConnectectComps[i]*(4-i);
        return ans;
    }
};