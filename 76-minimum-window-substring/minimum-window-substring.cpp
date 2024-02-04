class Solution {
public:
    bool check(unordered_map<char,int>& mp, string &t){
        for(auto &pair : mp) if(pair.second > 0) return false;  
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto &i : t) mp[i]++;

        int n = s.length(),l=0,r=0,mini=INT_MAX,start = 0;
        while(r<n) {
            mp[s[r]]--;
            while (check(mp, t)) {
                if(r-l+1 < mini) {
                    mini=r-l+1;
                    start = l; 
                }
                mp[s[l]]++; l++;
            }
            r++;
        }
        return (mini == INT_MAX) ? "" : s.substr(start, mini);
    }
};
