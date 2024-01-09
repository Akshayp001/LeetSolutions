bool cmp(vector<int> &a, vector<int> &b) {
   return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
}

class Solution {
public:
    // int solve(vector<vector<int>>& evp, int curr, int prev, vector<vector<int>>& dp) {
    //     if (curr >= evp.size()) return 0;

    //     if (dp[prev + 1][curr] != -1) return dp[prev + 1][curr];

    //     int take = 0, notTake = 0;
    //     if (prev == -1 || (evp[curr][0] > evp[prev][0] && evp[curr][1] > evp[prev][1])) {
    //         take = 1 + solve(evp, curr + 1, curr, dp);
    //     }
    //     notTake = solve(evp, curr + 1, prev, dp);
    //     return dp[prev + 1][curr] = max(take, notTake);
    // }

    int maxEnvelopes(vector<vector<int>>& envp) {
        int n = envp.size();
        sort(envp.begin(), envp.end(), cmp);

        // //one state tabulation

        // vector<int> dp(n,1);
        // int maxi = 1;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(envp[i][0]>envp[j][0] && envp[i][1]>envp[j][1]){
        //             dp[i] = max(dp[i],dp[j]+1);
        //             maxi = max(maxi,dp[i]);
        //         }
        //     }
        // }
        // return maxi;     

        vector<int> ans;
        ans.push_back(envp[0][1]);   
        for(int i=1;i<n;i++){
            int temp = ans.back();
            if(temp<envp[i][1]){
                ans.push_back(envp[i][1]);
            }else{
                int ind = lower_bound(ans.begin(),ans.end(),envp[i][1])-ans.begin();
                ans[ind] = envp[i][1];
            }
        }
        return ans.size();
    }
};
