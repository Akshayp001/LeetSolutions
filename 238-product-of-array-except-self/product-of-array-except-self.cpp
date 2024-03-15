class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> r(n),l(n);
        int ctr=1,cnt=1;
        for(int i=0;i<n;i++){
            r[i]=ctr; ctr*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            l[i]=cnt; cnt*=nums[i];
        }
        for(int i=0;i<n;i++) nums[i]=r[i]*l[i];
        return nums;
    }
};