class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> p;
        int n = names.size();
        for(int i=0;i<n;i++) p.push_back(make_pair(heights[i],names[i]));
        sort(p.rbegin(),p.rend());
        vector<string> ans;
        for(auto &i:p) ans.push_back(i.second);
        return ans;        
    }
};