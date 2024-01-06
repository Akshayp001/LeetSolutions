class Solution {
public:

    int findOps(int n,vector<int>&nums){
        int ops=0;
        for(auto num:nums) ops+=abs(num-nums[n]);
        return ops;
    }
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0,a=0,b=0;
        
        a = n/2 ;
        if(!(n&1)) b = n/2 - 1;

        if(b==0) ans=findOps(a,nums);
        else ans=min(findOps(a,nums),findOps(b,nums));

        return ans;
        
    }
};