class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> up;
        if(s.length()<=10) return {};
        for(int i=0;i<=s.length()-10;i++){
            up[s.substr(i,10)]++;
        }
        vector<string> ans;
        for(auto &i:up){
            if(i.second>1) ans.push_back(i.first);
        }
        return ans;        
    }
};