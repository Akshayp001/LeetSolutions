class Solution {
public:
    int setBits(int n){
        int cnt=0;
        while(n){
            if(n&1) cnt++;
            n=n>>1;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(setBits(i)==k) ans+=nums[i];
        }
        return ans;        
    }
};