class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        prefix[0] = 1; 
        int count = 0, oddCount = 0;

        for (int i = 0; i < n; i++) {
            oddCount += nums[i] % 2;
            if (oddCount >= k) {
                count += prefix[oddCount - k];
            }
            prefix[oddCount]++;
        }

        return count;
    }
};
