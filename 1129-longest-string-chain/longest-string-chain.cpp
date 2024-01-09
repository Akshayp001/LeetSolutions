bool cmp(string &s,string &t){
    return s.length()<t.length();
}

class Solution {
public:
    bool isPred(string &prev,string &curr){
        if(curr.length()!=(prev.length()+1)) return false;

        int flag=1;
        int i=0,j=0;
        while(i<prev.length() && j<curr.length()){
            if(prev[i]==curr[j]){
                i++;j++;
                continue;
            }
            else if(flag){
                flag=0;j++;
            }
            else return false;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPred(words[j],words[i])){
                    dp[i] = max(dp[i],dp[j]+1);
                    maxi= max(maxi,dp[i]);
                }
            }
        }
        return maxi;
        
    }
};