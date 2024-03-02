class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int ctr=0;
        for(int j=1;j<n-1;j++){
            int i=j-1, k=j+1;
            while(i>=0 && k<n){
                if(nums[k]-nums[j]==diff && nums[j]-nums[i]==diff){
                    ctr++;
                    k++; i--;
                }
                else if(nums[k]-nums[j]<diff) k++;
                else if(nums[j]-nums[i]<diff) i--; 
                else break;
            }
        }
        return ctr;
        
    }
};