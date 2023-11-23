class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = l.size();
        
        for (int i = 0; i < n; ++i) {
            int left = l[i];
            int right = r[i];
            vector<int> subarray(nums.begin() + left, nums.begin() + right + 1);
            sort(subarray.begin(), subarray.end());
            
            bool isArithmetic = true;
            int diff = subarray[1] - subarray[0];
            for (int j = 2; j < subarray.size(); ++j) {
                if (subarray[j] - subarray[j - 1] != diff) {
                    isArithmetic = false;
                    break;
                }
            }
            
            ans.push_back(isArithmetic);
        }

        return ans;
    }
};
