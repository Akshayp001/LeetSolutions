class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        int n = s.length();
        while(i<j){
            if(s[i]==s[j]){
                char t = s[i];
                while(i<=j){
                    if(s[i]==t){
                        i++; n--;
                    }else if(s[j]==t){
                        j--; n--;
                    }else break; 
                }
            }else break;
            
        }
        return n;
    }
};