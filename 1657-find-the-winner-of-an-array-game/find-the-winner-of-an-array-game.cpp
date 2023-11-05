class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if (k >= n) {
            return *max_element(arr.begin(), arr.end());
        }

        int curr = arr[0];
        int consecutiveWins = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] > curr) {
                curr = arr[i];
                consecutiveWins = 1;
            } else {
                consecutiveWins++;
            }

            if (consecutiveWins == k) {
                return curr;
            }
        }

        return curr;
    }
};
