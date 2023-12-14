#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0) return {}; 
        int cols = grid[0].size();

        vector<int> r1(rows, 0);
        vector<int> r0(rows, 0);
        vector<int> c0(cols, 0);
        vector<int> c1(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    r1[i]++;
                    c1[j]++;
                } else {
                    r0[i]++;
                    c0[j]++;
                }
            }
        }

        vector<vector<int>> a(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                a[i][j] = r1[i] + c1[j] - r0[i] - c0[j];
            }
        }

        return a;
    }
};
