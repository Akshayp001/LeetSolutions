class Solution {
public:
    bool solve(int i,int j,string &s,vector<vector<int>> &dp){
        if(i>j) return false;
        if(i==j) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j] && (i==j-1 || solve(i+1,j-1,s,dp))){
            dp[i][j]=1;
        }
        solve(i,j-1,s,dp);
        solve(i+1,j,s,dp);

        if(dp[i][j]==-1) dp[i][j]=0;
        return dp[i][j];
    }

    int countSubstrings(string s){
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        solve(0,n-1,s,dp);
        int count=0;
        for(auto i:dp) for(auto j:i) count+= j==1?1:0;
        return count ;        
    }
};