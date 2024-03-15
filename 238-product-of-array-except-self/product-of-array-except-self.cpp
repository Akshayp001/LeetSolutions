class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n),b(n);
        int ct=1,c=1;
        for(int i=0;i<n;i++){
            a[i]=ct; ct*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            b[i]=c; c*=nums[i];
        }
        for(int i=0;i<n;i++) nums[i]=a[i]*b[i];
        return nums;
    }
};