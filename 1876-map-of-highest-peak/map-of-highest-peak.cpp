class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(),m = isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(isWater[i][j]==1){
                    q.push({i,j});
                    ans[i][j]=0;
                }
        
        while(!q.empty()){
            pair<int,int> temp = q.front();
            int x =temp.first,y=temp.second;
            q.pop();
            if(x+1<n && (ans[x+1][y]-ans[x][y])>1){
                q.push({x+1,y});
                ans[x+1][y]=ans[x][y]+1;
            }
            if(x-1>=0 && (ans[x-1][y]-ans[x][y])>1){
                q.push({x-1,y});
                ans[x-1][y]=ans[x][y]+1;
            }
            if(y+1<m && (ans[x][y+1]-ans[x][y])>1){
                q.push({x,y+1});
                ans[x][y+1]=ans[x][y]+1;
            }
            if(y-1>=0 && (ans[x][y-1]-ans[x][y])>1){
                q.push({x,y-1});
                ans[x][y-1]=ans[x][y]+1;
            }  
        }
        return ans;
    }
};