class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        map<pair<int,long long>,int> dp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long d = (long long)nums[i]-(long long)nums[j];
                dp[{i,d}]+=1;
                if(dp.find({j,d}) !=dp.end()){
                    dp[{i,d}] += dp[{j,d}];
                    ans+=dp[{j,d}];
                }
            }
        }
        return ans;        
    }
};