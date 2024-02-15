class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix;
        long long t = 0;
        for(auto &i:nums) t+=i,prefix.push_back(t);    
          
        long long ans=-1;
        for(int i=n-1;i>=2;i--){
            if(prefix[i-1]>nums[i]){
                ans = prefix[i];
                break;
            }
        }
        return ans;      
    }
};