class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // vector<int> bits(32, 0);
        // for (auto num : nums) {
        //     for (int j = 0; j < 32; j++) {
        //         bits[j] += ((num >> j) & 1);
        //     } 
        // }
        // int ans = 0;
        // for (int i = 0; i < 32; i++) {
        //     if (bits[i] % 3 == 1) {
        //         ans |= (1 << i); 
        //     }
        // }
        int ans=0;
        int ones=0,twos=0;
        for(auto &i:nums){
            ones = (ones^i)&(~twos);
            twos = (twos^i)&(~ones);
        }
        return ones;
    }
};
