class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi=-1;
        for(int i=0;i<num.length()-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                if((num[i]-'0') > maxi){
                    maxi = num[i]-'0';
                }
            }            
        }
        string ans="";
        if(maxi!=-1){
            ans+=(maxi+'0');
            ans+=(maxi+'0');
            ans+=(maxi+'0');
        }
        return ans;
    }
};