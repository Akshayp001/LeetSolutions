class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n, -1);
        int maxi = 1;
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if ((long)dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                    if (dp[i] > maxi) {
                        maxi = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }
        
        vector<int> ans;
        while (maxi > 0 && maxIndex >= 0 && maxIndex < n) {
            ans.push_back(nums[maxIndex]);
            maxIndex = hash[maxIndex];
            maxi--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
