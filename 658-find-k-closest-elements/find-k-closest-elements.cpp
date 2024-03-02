class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int n = arr.size();
        vector<int> ans;
        int i = ind - 1, j = ind;
        
        while (k--) {
            if (i >= 0 && j < n) {
                if (abs(arr[i] - x) <= abs(arr[j] - x)) {
                    ans.push_back(arr[i--]);
                } else {
                    ans.push_back(arr[j++]);
                }
            } else if (i >= 0) {
                ans.push_back(arr[i--]);
            } else if (j < n) {
                ans.push_back(arr[j++]);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
