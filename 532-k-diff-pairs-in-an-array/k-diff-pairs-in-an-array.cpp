class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (auto &i : nums)
            mp[i]++;

        for (auto &m : mp) {
            if (k == 0) {
                if (m.second >= 2) {
                    ans++;
                }
            } else {
                if (mp.find(m.first + k) != mp.end()) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
