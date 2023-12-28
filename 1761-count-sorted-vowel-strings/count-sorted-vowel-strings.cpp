class Solution {
public:
    int countVowelStrings(int n) {
    // // tabulation
    // vector<int> dp(5,1);
    // int t = 5;
    // for(int i=1;i<n;i++){
    //     t = 1; dp[4]=1;
    //     for(int j=3;j>=0;j--){
    //         dp[j] = dp[j+1] + dp[j];
    //         t+=dp[j];
    //     }
    // }
    // return t;  
    // space optimisation
    int a=1, e=1, i=1, o=1, u=1;
        while(--n){
            o += u;
            i += o;
            e += i;
            a += e;
        }
    return a+e+i+o+u;
    }
};