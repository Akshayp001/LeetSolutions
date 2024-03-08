#include <vector>
#include <cmath>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::vector<int> bits(32, 0);
        for (auto num : nums) {
            for (int j = 0; j < 32; j++) {
                bits[j] += ((num >> j) & 1);
            } 
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] % 3 == 1) {
                ans |= (1 << i); 
            }
        }
        return ans;
    }
};
