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

        //Tabulation Two states..
        // if(n==0) return 0;
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // // return solve(nums,0,-1,dp);    
        // for(int i=n-1;i>=0;i--){
        //     for(int j=i-1;j>=-1;j--){
        //         int np = dp[i+1][j+1];
        //         int t =0;
        //         if(j==-1 || nums[i]>nums[j]){
        //             t = 1+ dp[i+1][i+1];
        //         }
        //         dp[i][j+1]=max(t,np);
        //     }
        // }  

        // //One State Tabulation
        // vector<int> dp(n,1);
        // int maxi =1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i]){
        //             dp[i] = max(dp[i],dp[j]+1);
        //             maxi = max(maxi,dp[i]);
        //         }
        //     }
        // }
        // return maxi;  

        //Binary Search Approach
        vector<int> LIS;

        for(auto num:nums){
            if(LIS.size()==0){
                LIS.push_back(num);
                continue;
            }
            if(num>LIS.back()){
                LIS.push_back(num);
            }else{
                int ub = lower_bound(LIS.begin(),LIS.end(),num) - LIS.begin();
                LIS[ub]=num;
            }
        }
        return LIS.size();
    }
};