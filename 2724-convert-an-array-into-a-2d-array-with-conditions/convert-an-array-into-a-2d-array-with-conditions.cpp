class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxi = 0;
        for (auto i : nums) {
            m[i]++;
            maxi = max(maxi, m[i]);
        };
        vector<vector<int>> ans(maxi, vector<int>()); 
        
        for (auto mi : m) {
            int freq = mi.second; 
            int i = 0;
            while (freq--) { 
                ans[i++].push_back(mi.first);
            }
        }
        return ans;
    }
};
