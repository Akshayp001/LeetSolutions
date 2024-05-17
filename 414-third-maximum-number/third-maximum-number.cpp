class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int>> s;
        for(auto &i:nums) s.insert(i);
        if(s.size()<3) return *s.begin();
        return *next(s.begin(), 2);
    }
};