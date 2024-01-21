class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> s;
        int ans =0;
        for(int i=0;i<n;i++){
            vector<int> temp;
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]%p==0){ 
                    cnt++;
                }
                temp.push_back(nums[j]);
                if(cnt <=k) s.insert(temp);
            }
        }
        return s.size();
        
    }
};