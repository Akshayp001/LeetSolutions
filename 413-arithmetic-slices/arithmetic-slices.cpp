class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int curr=0,total=0;
        if(n<3) return 0;

        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]) total+=++curr;
            else curr=0;
        }
        return total;
        
    }
};