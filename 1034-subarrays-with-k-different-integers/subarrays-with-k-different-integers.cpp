class Solution {
    int n;
    int solve(vector<int> &nums,int k){
        unordered_map<int,int> m;
        int cnt=0;
        int i=0,j=0;
        while(j<n){
            m[nums[j]]++;
            while(m.size()>k){
                if(m[nums[i]]==1) m.erase(nums[i]);
                else m[nums[i]]--;
                i++;
            }
            cnt+=(j-i+1); j++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        n=nums.size();
        return solve(nums,k)-solve(nums,k-1);
    }
};