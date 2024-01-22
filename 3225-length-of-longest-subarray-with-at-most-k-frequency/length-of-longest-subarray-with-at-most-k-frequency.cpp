#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> m;
        int n = nums.size();
        int s = 0, e = 0; 
        int maxi = 0;

        while (e < n) {
            m[nums[e]]++;

            while (m[nums[e]] > k) {
                m[nums[s]]--;
                s++;
            }

            maxi = max(maxi, e - s + 1);
            e++;
        }

        return maxi;
    }
};
