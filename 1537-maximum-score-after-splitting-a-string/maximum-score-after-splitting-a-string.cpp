class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zeros = 0;
        for(auto si:s) if(si=='1') ones++;
        int maxi = INT_MIN;

        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='1'){
                ones--;
            }else{
                zeros++;
            }
            maxi = max(maxi,ones+zeros);
        }
        return maxi;        
    }
};