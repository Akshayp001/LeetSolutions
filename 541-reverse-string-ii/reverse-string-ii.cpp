class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int i=0,j=k;
        if(j>n){
            reverse(s.begin(),s.end());
            return s;
        }
        while(j<=n){
            reverse(s.begin()+i,s.begin()+j);
            i+=2*k;
            j+=2*k;
            if(j>n){
                reverse(s.begin()+i, s.end());
                return s;
            }
        }
        return s;
    }
};