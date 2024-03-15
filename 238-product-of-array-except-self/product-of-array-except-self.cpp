class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int rcnt=0;
        int n = nums.size();
        long long prod=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                prod*=nums[i];
            }else rcnt++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(rcnt>=2){
                ans.push_back(0);
            }
            else if(rcnt==1){
                if(nums[i]==0) ans.push_back(prod);
                else ans.push_back(0);
            }else{
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};