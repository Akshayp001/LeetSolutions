class Solution {
public:

    int solve(int time,int ind,vector<int> &sat,vector<vector<int>> &dp){
        if(ind==sat.size()){
            return 0;
        }

        if(dp[ind][time]!=-1){
            return dp[ind][time];
        }

        //take 
        int take = sat[ind]*time + solve(time+1,ind+1,sat,dp);
        //no takr
        int notTake =  0 + solve(time,ind+1,sat,dp);

        return dp[ind][time]=max(take,notTake);

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(1,0,satisfaction,dp);  
               
    }
};