class DisjointSet {
    vector<int> parent;
    int islands;
public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        islands = 0;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionSets(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            parent[pu] = pv;
            islands--; 
        }
    }

    void inc() {
        islands++;
    }

    int get() {
        return islands;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        if (cols == 0) return 0;

        DisjointSet ds(rows * cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    ds.inc();
                    int idx = i * cols + j;
                    if (i > 0 && grid[i - 1][j] == '1') 
                        ds.unionSets(idx, idx - cols);
                    if (j > 0 && grid[i][j - 1] == '1')
                        ds.unionSets(idx, idx - 1);
                }
            }
        }
        return ds.get();
    }
};