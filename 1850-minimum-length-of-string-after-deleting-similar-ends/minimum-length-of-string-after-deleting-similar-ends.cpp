class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                char t = s[i];
                while(i<=j){
                    if(s[i]==t) i++, n--;
                    else if(s[j]==t) j--, n--;
                    else break; 
                }
            }else break; 
        }
        return n;
    }
};