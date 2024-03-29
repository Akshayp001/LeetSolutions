class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dp[0][i]= matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int left=INT_MAX,right=INT_MAX,top=INT_MAX;
                if(j-1>=0){
                    left = matrix[i][j]+dp[i-1][j-1];
                }
                top = matrix[i][j]+dp[i-1][j];
                if(j+1<n){
                    right = matrix[i][j]+ dp[i-1][j+1];
                }
                dp[i][j] = min({left,top,right});
            }
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};