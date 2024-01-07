#define INF 1e9

class Solution {
public:
    void floydWarshall(vector<vector<int>> &adj){
        int n = adj.size();

        for(int k = 0; k < 26; k++){
            for(int i = 0; i <26 ; i++){
                for(int j = 0; j < 26; j++){
                        adj[i][j]=min(adj[i][j],adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    long long minimumCost(string src, string tgt, vector<char>& og, vector<char>& ch, vector<int>& cost){
        vector<vector<int>> adj(26,vector<int>(26,INF));
        
        for(int i = 0; i < 26; i++) 
            for(int j = 0; j < 26; j++) 
                if(i == j) adj[i][j] = 0;
        
        for(int i = 0; i < og.size(); i++){
            adj[og[i]-'a'][ch[i]-'a'] = min(adj[og[i]-'a'][ch[i]-'a'],cost[i]);
        }

        floydWarshall(adj);

        long long ans = 0;
        for(int i = 0; i < src.length(); i++){
            if(adj[src[i]-'a'][tgt[i]-'a'] == INF) return -1;
            else ans += adj[src[i]-'a'][tgt[i]-'a'];            
        }
        return ans;     
    }
};
