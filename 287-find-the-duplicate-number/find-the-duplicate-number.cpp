class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //approach 1
        // int n = nums.size()-1;
        // for(int i:nums){
        //     int ind = abs(i);
        //     if(nums[ind]<0) return ind;
        //     nums[ind]*=-1;
        // }
        //approach 2
        int n=nums.size();
        vector<int> hash(n,0);
        
        for(int i=0;i<n;i++) hash[nums[i]]++;
        for(int i=0;i<n;i++) if(hash[i]>=2) return i;
        return n;        
    }
};