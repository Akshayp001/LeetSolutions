#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, int x, int y, int free, int cnt) {
        if (grid[x][y] == 2) {
            if (cnt == free) return 1;
            return 0;
        }
        if (grid[x][y] == -2 || grid[x][y] == -1) {
            return 0;
        }

        grid[x][y] = -2;

        int ans = 0;
        if (x + 1 < grid.size()) ans += solve(grid, x + 1, y, free, cnt + 1);
        if (x - 1 >= 0) ans += solve(grid, x - 1, y, free, cnt + 1);
        if (y + 1 < grid[0].size()) ans += solve(grid, x, y + 1, free, cnt + 1);
        if (y - 1 >= 0) ans += solve(grid, x, y - 1, free, cnt + 1);

        grid[x][y] = 0; 

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int obst = 0, free = 0, x = 0, y = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                } else if (grid[i][j] == -1) {
                    obst++;
                } else if (grid[i][j] == 0) {
                    free++;
                }
            }
        }

        return solve(grid, x, y, free + 1, 0); // +1 for the starting cell
    }
};
