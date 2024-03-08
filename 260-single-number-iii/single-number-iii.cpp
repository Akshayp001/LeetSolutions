#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(auto &i:nums) xorr ^= i;
        
        // Finding the rightmost set bit
        int set = 0;
        int t = xorr;
        while((t & 1) != 1) { // Check if the rightmost bit is set
            set++;
            t >>= 1;
        }
        
        int ans = 0;
        for(auto &i:nums) {
            if((i >> set) & 1) 
                ans ^= i;
        }
        
        return {ans, xorr^ans};
    }
};
