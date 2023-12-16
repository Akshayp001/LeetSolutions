class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(auto si:s){
            m1[si]++;
        }
        for(auto si:t){
            m2[si]++;
        }
        return m1==m2; 
    }
};