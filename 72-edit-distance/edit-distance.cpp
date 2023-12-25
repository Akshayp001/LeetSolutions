class Solution {
public:

    int solve(string s,string t,int x,int y,vector<vector<int>>&dp){
        if(x<0 || y<0) return max(x,y)+1;

        if(dp[x][y]!=-1) return dp[x][y];
        if(s[x]==t[y]) return dp[x][y]=solve(s,t,x-1,y-1,dp);
        
        int insert = solve(s,t,x,y-1,dp);
        int replace = solve(s,t,x-1,y-1,dp);
        int del = solve(s,t,x-1,y,dp);
        return dp[x][y]=1+min({insert,replace,del});
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,n-1,m-1,dp);

    }
};