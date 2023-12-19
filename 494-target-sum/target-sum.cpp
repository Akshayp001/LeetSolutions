class Solution {
public:
    int solve(int ind,vector<int> &nums,int target){
        if(ind<0){
            if(target == 0) return 1;
            else return 0;
        }

        return solve(ind-1,nums,target-nums[ind])+solve(ind-1,nums,target+nums[ind]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums.size()-1,nums,target);
    }
};