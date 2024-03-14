class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> pref;
        int t=0,cnt=0,n=nums.size();
        for(auto &i:nums){
            t+=i;
            pref.push_back(t);
            if(t==goal) cnt++;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pref[i]-pref[j]==goal) cnt++;
            }
        }
        return cnt;        
    }
};