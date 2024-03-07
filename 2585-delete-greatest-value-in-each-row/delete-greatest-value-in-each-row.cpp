class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0;i<n;i++){
            sort(grid[i].begin(),grid[i].end());
        }
        int m = grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            int maxi = 0;
            for(int j=0;j<n;j++) maxi = max(grid[j][i],maxi);
            ans+=maxi;
        }
        return ans;
    }
};