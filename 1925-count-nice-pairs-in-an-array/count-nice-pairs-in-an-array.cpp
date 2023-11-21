#include <unordered_map>
#include <vector>

class Solution {
public:
    int rev(int num){
        int revNum = 0;
        while(num){
            revNum = revNum * 10 + num % 10;
            num /= 10;
        }
        return revNum;
    }
    
    int countNicePairs(std::vector<int>& nums) {
        int count = 0;
        const int MOD = 1e9 + 7;
        
        std::unordered_map<int, int> freq;
        
        for (int num : nums) {
            int diff = num - rev(num);
            count = (count + freq[diff]) % MOD;
            freq[diff]++;
        }
        
        return count;
    }
};
