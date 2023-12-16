class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1;
        for(auto si:s){
            m1[si]++;
        }
        for(auto si:t){
            m1[si]--;
        }
        
        for(auto i:m1){
            if(i.second!=0) return false;
        }
        return true;
    }
};