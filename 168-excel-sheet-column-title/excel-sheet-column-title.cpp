class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        while(n){
            int rem = (n-1)%26;
            char c=(char)('A'+rem);
            ans=c+ans;
            n=(n-1)/26;
        }
        return ans;        
    }
};