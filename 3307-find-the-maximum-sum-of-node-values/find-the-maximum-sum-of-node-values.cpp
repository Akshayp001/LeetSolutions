#define ll long long

class Solution {
public:
    ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<int> tmp;
        for(int i=0;i<n;i++){
            ll t=(ll)nums[i]^k;
            if(t>nums[i]) tmp.push_back(i);
        }
		ll sol=0;
        
        for(int i=0;i<n;i++) sol+=(ll)nums[i];
        ll maxii=sol;
        for(int i=0;i<tmp.size();i++) sol = sol-nums[tmp[i]]+((ll)nums[tmp[i]]^k);
        if(tmp.size()%2==0) return sol;
        else{
            for(int i=0;i<tmp.size();i++){
                ll t=sol- ((ll)nums[tmp[i]]^k) +nums[tmp[i]];
                maxii=max(maxii,t);
            }
            vector<int> check(n,0);
            for(int i=0;i<tmp.size();i++) check[tmp[i]]=1;
            for(int i=0;i<n;i++){
                if(check[i]==0){
                    ll t=sol-nums[i]+((ll)nums[i]^k);
                    maxii=max(maxii,t);
                }
            }
            return maxii;
        }
    }
};