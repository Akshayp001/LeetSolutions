class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi = 0;
        unordered_map<int,int> m;
        
        for(auto ni:nums){
            m[ni]++;
            maxi = max(maxi,m[ni]);
        }
        
        int ans = 0;
        for(auto it:m){
            if(it.second==maxi){
                ans+=maxi;
            }
        }
        return ans;
        
    }
};