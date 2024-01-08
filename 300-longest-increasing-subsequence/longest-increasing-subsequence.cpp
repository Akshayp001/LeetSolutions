class Solution {
public:

    // //memoisation
    // int solve(vector<int>& nums,int i,int prev,vector<vector<int>>&dp){
    //     if(nums.size()==i) return 0;

    //     if(dp[i][prev+1]!=-1) return dp[i][prev+1];

    //     int np =  solve(nums,i+1,prev,dp);

    //     int t=0;
    //     if(prev==-1 || nums[i]>nums[prev]){
    //         t=1+solve(nums,i+1,i,dp);
    //     }
    //     return dp[i][prev+1]=max(t,np);   
    // }

    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // return solve(nums,0,-1,dp);    
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int np = dp[i+1][j+1];
                int t =0;
                if(j==-1 || nums[i]>nums[j]){
                    t = 1+ dp[i+1][i+1];
                }
                dp[i][j+1]=max(t,np);
            }
        }  
        return dp[0][0];  
    }
};