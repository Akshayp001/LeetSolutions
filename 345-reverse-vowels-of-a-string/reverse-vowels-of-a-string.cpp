class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string reverseVowels(string s) {
        vector<int> inds;
        string vowels="";
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
                inds.push_back(i);
            }
        }
        reverse(vowels.begin(),vowels.end());
        for(int i=0;i<inds.size();i++){
            s[inds[i]]=vowels[i];
        } 
        return s;       
    }
};