class Solution {
public:

    int maximumBags(vector<int>& cap, vector<int>& rocks, int k) {
        int n =rocks.size();
        int ans=0;
        for(int i=0;i<n;i++) cap[i]-=rocks[i];
        sort(cap.begin(),cap.end());
        int i=0;
        while(k>0 && i<n){
            if(cap[i]<=k) k-=cap[i],cap[i]=0;
            ans+=(cap[i]==0);
            i++;            
        }
        return ans;        
    }
};