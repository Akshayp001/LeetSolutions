class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=-1;
        int m=-1;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi = nums[i];
                ind=i;
            }
        }
        nums[ind]=-1;
        for(auto n:nums){
            m = max(m,n);
        }
        return ((m-1)*(maxi-1));        
    }
};