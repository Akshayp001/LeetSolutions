class Solution {
public:
    vector<int> gen(){
        vector<int> arr;
        for(int i=1;i<=100;i++){
            arr.push_back(i*i);
        }
        return arr;
    }
    vector<int> sqrs = gen();

    int solve(int n,vector<int> &dp){
        if(n==0) return 0;
        if(n<0) return 1e5;

        if(dp[n]!=-1) return dp[n];

        int last = lower_bound(sqrs.begin(),sqrs.end(),n)-sqrs.begin();
        int mini = INT_MAX;
        for(int i=last;i>=0;i--){
            if(sqrs[i]>n) continue;
            mini = min(mini,1+solve(n-sqrs[i],dp));
        }
        return dp[n]=mini;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);        
        return solve(n,dp);
    }
};