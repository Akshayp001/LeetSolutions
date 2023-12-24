class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int x=str1.length();
        int y=str2.length();

        vector<vector<int>> dp(x+1,vector<int>(y+1,0));

        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }

        int lcslen = dp[x][y];

        int i=x,j=y;
        string lcs="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                lcs.push_back(str1[i-1]);
                i--;j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
        reverse(lcs.begin(),lcs.end());
        i=0;j=0;
        string scs;

        for(auto c:lcs){
            while(c!=str1[i]){
                scs.push_back(str1[i]);
                i++;
            }
            while(c!=str2[j]){
                scs.push_back(str2[j]);
                j++;
            }
            scs.push_back(c);
            i++;j++;
        }

        while(i<x){
                scs.push_back(str1[i]);
                i++;
            }
        while(j<y){
            scs.push_back(str2[j]);
            j++;
        }
        
        return scs;

        
    }
};