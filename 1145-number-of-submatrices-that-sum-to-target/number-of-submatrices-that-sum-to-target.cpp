#include <vector>

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> prefix(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    prefix[i][j] += prefix[i - 1][j];
                }
                if (j > 0) {
                    prefix[i][j] += prefix[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i - 1][j - 1];
                }
                prefix[i][j] += matrix[i][j];
            }
        }

        for (int top = 0; top < m; top++) {
            for (int bottom = top; bottom < m; bottom++) {
                for (int left = 0; left < n; left++) {
                    for (int right = left; right < n; right++) {
                        int current_sum = prefix[bottom][right];
                        if (top > 0) {
                            current_sum -= prefix[top - 1][right];
                        }
                        if (left > 0) {
                            current_sum -= prefix[bottom][left - 1];
                        }
                        if (top > 0 && left > 0) {
                            current_sum += prefix[top - 1][left - 1];
                        }

                        if (current_sum == target) {
                            ans++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
