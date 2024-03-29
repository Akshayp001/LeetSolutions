class Solution {
public:
    
    int rob(vector<int>& nums) {
        //Tabular Approach

        // if(nums.size()==0) return 0;
        // if(nums.size()==1) return nums[0];
        // vector<int> dp(nums.size(),0);
        // dp[0]=nums[0];
        // dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<nums.size();i++){
        //     dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        // }
        // return dp[nums.size()-1];    

        //Space Optimisation approach

        
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        int a=nums[0];
        int b= max(nums[0],nums[1]);
        int ans=b;

        for(int i=2;i<nums.size();i++){
            ans = max(a+nums[i],b);
            a =b;
            b= ans;
        }
        return ans;
    }
};