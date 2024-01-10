class Solution {
public:
    void fillAdj(TreeNode* root, unordered_map<int, unordered_map<int, int>>& adj) {
        if (root == nullptr) return;

        if (root->left) {
            int p = root->val;
            int lc = root->left->val;
            adj[p][lc] = 1;
            adj[lc][p] = 1;
            fillAdj(root->left, adj);
        }
        
        if (root->right) {
            int p = root->val;
            int rc = root->right->val;
            adj[p][rc] = 1;
            adj[rc][p] = 1;
            fillAdj(root->right, adj);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_map<int, int>> adj;
        fillAdj(root, adj);

        unordered_map<int, int> visited;
        queue<int> q;

        q.push(start);
        visited[start] = 1;
        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int temp = q.front();
                q.pop();
                for (auto i : adj[temp]) {
                    if (visited[i.first] == 0) {
                        visited[i.first] = 1;
                        q.push(i.first);
                    }
                }
            }
            count++;
        }

        return count - 1;
    }
};
