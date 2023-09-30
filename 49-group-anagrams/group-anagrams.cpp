class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto str:strs){
            string sorted = str;
            sort(sorted.begin(),sorted.end());
            vector<string> a = mp[sorted];
            a.push_back(str);
            mp[sorted]=a;
        }
        vector<vector<string>> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
        }

};