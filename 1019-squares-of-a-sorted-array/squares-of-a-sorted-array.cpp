class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(); vector<int> ans(n); 
        int i=0,j=n-1,k=n-1;
        while(i<j){
            int a=abs(nums[i]),b=abs(nums[j]);
            if(a==b){
                ans[k--]=a*a; i++;
                ans[k--]=b*b; j--;
            }else if(b>a) ans[k--]=b*b,j--;
            else ans[k--]=a*a,i++;
            
        }
        if(i==j) ans[k]=nums[i]*nums[i];
        return ans;        
    }
};