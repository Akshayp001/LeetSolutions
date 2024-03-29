class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> n0;
        for(auto &i:nums) if(i!=0) n0.push_back(i);
        int n=n0.size();
        if(n<=2) return 0;
        sort(n0.begin(),n0.end());
        int ans = max((n0[0]*n0[1]*n0[n-1]),(n0[n-3]*n0[n-2]*n0[n-1]));
        if(n<nums.size()) return max(0,ans);
        return ans;      
    }
};