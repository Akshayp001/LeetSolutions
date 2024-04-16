class Solution {
public:

    void bfs(TreeNode* &root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            root = newRoot;
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            if (--d == 1) {
                for (int i = 0; i < sz; i++) {
                    auto t = q.front(); q.pop();
                    TreeNode* l = new TreeNode(v);
                    TreeNode* r = new TreeNode(v);
                    l->left = t->left;
                    r->right = t->right;
                    t->left = l;
                    t->right = r;
                }
                return;
            }
            for (int i = 0; i < sz; i++) {
                auto t = q.front(); q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        bfs(root, val, depth);
        return root;
    }
};