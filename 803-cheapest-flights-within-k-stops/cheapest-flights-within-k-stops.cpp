class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9;
        vector<vector<int>> dp(k + 2, vector<int>(n, INF)); 
        dp[0][src] = 0;
        
        for (int i=1;i<=k+1;++i) {
            dp[i][src] = 0;
            for (auto& flight : flights) {
                int from = flight[0], to = flight[1], cost=flight[2];
                if (dp[i-1][from] != INF) { 
                    dp[i][to]=min(dp[i][to], dp[i-1][from] + cost); 
                }
            }
        }
        return (dp[k+1][dst]==INF)?-1: dp[k+1][dst]; 
    }
};
