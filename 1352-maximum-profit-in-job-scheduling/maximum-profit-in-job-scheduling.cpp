
class Solution {
public:
    
    int solve(vector<vector<int>> &info,vector<int> &sTime,int ind,vector<int> &dp){
        int n = info.size();
        if(ind>=n) return 0;

        if (dp[ind]!=-1) return dp[ind];
        int take=0,notTake=0;
        //Not take
        notTake+=solve(info,sTime,ind+1,dp);
        //take
        int reqind = lower_bound(sTime.begin(),sTime.end(),info[ind][1])-sTime.begin();
        take = info[ind][2]+solve(info,sTime,reqind,dp);
        return dp[ind]=max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> info;
        int n = startTime.size();
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            info.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(info.begin(),info.end());
        sort(startTime.begin(),startTime.end());
        return solve(info,startTime,0,dp);        
    }
};