class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> s;
        for(auto &i:startWords){
            sort(i.begin(),i.end());
            s.insert(i);
        }
        int ans = 0;
        for(string &str:targetWords){
            sort(str.begin(),str.end());
            for(int i=0;i<str.length();i++){
                string tgt = str.substr(0,i)+str.substr(i+1);
                if(s.find(tgt)!=s.end()){
                    ans++;
                    break;
                }
            }   
        }
        return ans;
    }
};