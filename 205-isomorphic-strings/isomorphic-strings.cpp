class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,char> m1;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end() && m1.find(t[i])==m1.end()){
                m[s[i]]=t[i];
                m1[t[i]]=s[i];
            }else{
                if(m[s[i]]!=t[i] || m1[t[i]]!=s[i]) return false;
            }
        }
        return true;
        
    }
};