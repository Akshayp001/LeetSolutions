class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        long long i=0,j=0,kcnt=0,ans=0;
        int n = nums.size();
        while(j<n){
            if(nums[j]==maxi) kcnt++;
            while(kcnt>=k){
                ans+=(n-j);
                if(nums[i]==maxi) kcnt--;
                i++;
            }
            j++;
        }
        return ans;
        
    }
};