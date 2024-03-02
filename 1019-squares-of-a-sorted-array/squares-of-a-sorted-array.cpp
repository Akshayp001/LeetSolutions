class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans; int n = nums.size();
        int i=0,j=n-1;
        while(i<j){
            int a=abs(nums[i]),b=abs(nums[j]);
            if(a==b){
                ans.push_back(a*a); i++;
                ans.push_back(b*b); j--;
            }else if(b>a) ans.push_back(b*b),j--;
            else ans.push_back(a*a),i++;
            
        }
        if(i==j) ans.push_back(nums[i]*nums[i]);
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};