class Solution {
public:
    int minDistance(string word1, string word2) {
        int x=word1.length();
        int y=word2.length();

        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int match = dp[x][y];
        return x+y-match*2;
        
    }
};