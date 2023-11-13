class Solution {
public:
    void dfs(int node,vector<vector<int>> adj,vector<int> &vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjls(v);

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<int> vis(v,0);
        int count=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjls,vis);
            }
        }  
        return count;      
    }
};