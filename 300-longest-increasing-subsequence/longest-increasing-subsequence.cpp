class Solution {
public:
    int solve(vector<int>& nums,int i,int prev,vector<vector<int>>&dp){
        if(nums.size()==i) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int np =  solve(nums,i+1,prev,dp);

        int t=0;
        if(prev==-1 || nums[i]>nums[prev]){
            t=1+solve(nums,i+1,i,dp);
        }
        return dp[i][prev+1]=max(t,np);   
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(nums,0,-1,dp);        
    }
};