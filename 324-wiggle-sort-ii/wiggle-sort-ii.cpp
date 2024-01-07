class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        int ind = n-1;

        for(int i=1;i<n;i+=2) nums[i]=temp[ind--];

        for(int i=0;i<n;i+=2) nums[i]=temp[ind--];  
        return ;
    }
};