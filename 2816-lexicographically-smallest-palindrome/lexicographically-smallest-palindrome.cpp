class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n =s.length();
        int i=0,j=n-1;
        while(i<=j){
            char c=min(s[i],s[j]);
            s[j]=c; s[i]=c;
            i++;j--;
        }   
        return s;     
    }
};