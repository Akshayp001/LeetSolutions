class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int num =nums[0];
        int count =1;
        int n = nums.size()/3;
        vector<int> ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=num){
                if(count>n){
                    ans.push_back(num);
                }
                num = nums[i];
                count=1;
            }else{
                count++;
            }
        }

        if(count>n){
            ans.push_back(num);
        }
        return ans;
        
    }
};