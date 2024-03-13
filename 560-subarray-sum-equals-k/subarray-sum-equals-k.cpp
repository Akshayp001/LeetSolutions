class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        vector<int> pref;
        int t=0,n=nums.size();
        for(auto &i:nums){
            t+=i;
            if(t==k) cnt++;
            pref.push_back(t);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pref[i]-pref[j]==k) cnt++;        
            }
        }
        return cnt;
    }
};