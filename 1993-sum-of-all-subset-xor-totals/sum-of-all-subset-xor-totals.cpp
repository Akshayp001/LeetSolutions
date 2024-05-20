class Solution {
public:
    void xorsum(vector<int>& nums,int index,int xorSum,int &total){
        if(index>=nums.size()){
            total +=xorSum;
            return;
        }

        //Exclude 
        xorsum(nums,index+1,xorSum,total);
        //Include 
        xorsum(nums,index+1,xorSum^nums[index],total);
    }
    int subsetXORSum(vector<int>& nums) {
        int index =0;
        int xorSum = 0;
        int total =0;
        xorsum(nums,index,xorSum,total);
        return total;        
    }
};