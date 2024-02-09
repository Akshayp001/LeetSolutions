class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int m = grid.size();
        for(int i=0;i<m;i++){
            auto it =upper_bound(grid[i].rbegin(),grid[i].rend(),-1);
            if(it!=grid[i].rbegin() || grid[i][0]<0)
                count+=(it-grid[i].rbegin());
        }
        return count;        
    }
};