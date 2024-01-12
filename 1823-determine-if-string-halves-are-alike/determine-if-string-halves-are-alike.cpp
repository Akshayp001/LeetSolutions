class Solution {
public:

    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.length()/2;i++){
            if(isVowel(s[i])) cnt1++;
        }
        for(int i=s.length()/2;i<s.length();i++){
            if(isVowel(s[i])) cnt2++;
        }
        return cnt1==cnt2;        
    }
};