class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int m = grid.size();
        for(int i=0;i<m;i++){
            int s=0,e=grid[i].size();
            while(s<e){
                int mid =(e+s)/2;
                if(grid[i][mid]>=0){
                    s = mid+1;
                }else{
                    e= mid;
                }
            }
            count+=grid[i].size()-s;
        }
        return count;        
    }
};