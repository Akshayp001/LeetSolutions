class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long t = 0;
        for(auto &i:nums) t+=i;    

        long long ans=-1;
        for(int i=n-1;i>=2;i--){
            if(t-nums[i]>nums[i]){
                ans = t;
                break;
            }else t-=nums[i];
            
        }
        return ans;      
    }
};