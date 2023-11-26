class Solution {
public:
    bool solve(vector<int> &nums, int ind, int sum, vector<vector<int>> &dp) {
        if (sum == 0) return true;
        if (ind < 0 || sum < 0) return false;
        if (dp[ind][sum] != -1) return dp[ind][sum];

        bool take = solve(nums, ind - 1, sum - nums[ind], dp);
        bool ntake = solve(nums, ind - 1, sum, dp);

        return dp[ind][sum] = take || ntake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) sum += i;

        if (sum % 2 != 0) return false; 

        sum /= 2; 

        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return solve(nums, nums.size() - 1, sum, dp);
    }
};
