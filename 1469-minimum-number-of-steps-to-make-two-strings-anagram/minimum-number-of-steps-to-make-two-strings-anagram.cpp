class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        int ans = 0;

        for(auto &i:s) m[i]++;
        for(auto &i:t) if(m[i]) m[i]--; else ans++;
        
        return ans;
             
    }
};