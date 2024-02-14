class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n = nums.size();
        vector<int> ans(n,0);
        int e=0,o=1;
        for(auto i:nums){
            if(i>0) ans[e]=i,e+=2;
            else ans[o]=i,o+=2;
        }
        return ans;
    }
};