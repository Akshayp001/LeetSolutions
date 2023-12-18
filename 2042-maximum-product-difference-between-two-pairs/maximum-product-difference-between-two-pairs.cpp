#include <vector>
#include <climits>

class Solution {
public:
    int maxProductDifference(std::vector<int>& nums) {
        int maxi = 0, mini = 0;
        int maxii = 0, minii = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[maxi] < nums[i]) {
                maxi = i;
            }
            if (nums[mini] > nums[i]) {
                mini = i;
            }
        }

        maxii = (maxi == 0) ? 1 : 0;
        minii = (mini == 0) ? 1 : 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i == maxi || i == mini) continue;
            if (nums[maxii] < nums[i]) {
                maxii = i;
            }
            if (nums[minii] > nums[i]) {
                minii = i;
            }
        }

        return (nums[maxi] * nums[maxii]) - (nums[mini] * nums[minii]);
    }
};
