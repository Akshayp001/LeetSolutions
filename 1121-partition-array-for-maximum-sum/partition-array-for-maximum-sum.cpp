class Solution {
public:
    vector<int> arr;
    int sum(int from,int to){
        int maxi = 0;
        for(int i=from;i<=to;i++) maxi = max(maxi,arr[i]);
        return maxi*(to-from+1);
    }

int solve(int ind, int k,vector<int> &dp) {
    if (ind >= arr.size()) return 0;
    
    if(dp[ind]!=-1) return dp[ind];

    int maxi = arr[ind];
    for (int i = 1; i <= k && ind + i <= arr.size(); i++) {
        maxi = max(maxi, sum(ind, ind + i - 1) + solve(ind + i, k,dp));
    }
    
    return dp[ind]=maxi;
}

    int maxSumAfterPartitioning(vector<int>& ar, int k) {
        arr=ar;
        vector<int> dp(ar.size()+1,-1);
        return solve(0,k,dp);        
    }
};