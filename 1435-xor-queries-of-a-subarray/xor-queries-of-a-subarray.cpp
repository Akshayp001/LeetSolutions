class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pref;
        int t=0;
        pref.push_back(0);
        for(auto &i:arr) pref.push_back(i^t),t=i^t;
        vector<int> ans;
        for(auto &i:queries){
            int a = pref[i[0]]^pref[i[1]+1];
            ans.push_back(a);
        }  
        return ans;              
    }
};