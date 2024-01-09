#define INF 1e5
class Solution {
public:
    void floydWarshall(vector<vector<int>> &adj){
        int n = adj.size();
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);

    }
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(n,vector<int>(n,INF));
        for(auto i:edges){
            adj[i[0]][i[1]]=i[2];
            adj[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++) adj[i][i]=0;

        floydWarshall(adj); 
        int mini = INT_MAX;
        int maxInd = -1;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(adj[i][j]<=k) cnt++;
            }
            // cout<<"i ;"<<i<<"cnt ;"<<cnt<<endl;
            if(cnt<=mini){
                mini = cnt;
                maxInd = i;
            }
        }
        return maxInd;
    }
};