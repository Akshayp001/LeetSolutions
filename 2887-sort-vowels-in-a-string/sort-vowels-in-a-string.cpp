class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string sortVowels(string s) {
        vector<char> vowels;
        for(char i:s){
            if(isVowel(i)){
                vowels.push_back(i);
            }
        }
        sort(vowels.begin(),vowels.end());
        // if(vowels.size()>0) cout<<vowels[1]<<endl;
        int v=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=vowels[v++];
            }
        } 
        return s;       
    }
};