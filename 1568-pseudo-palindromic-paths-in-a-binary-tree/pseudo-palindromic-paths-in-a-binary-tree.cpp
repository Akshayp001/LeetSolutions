/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void preOrder(TreeNode* root,unordered_map<int,int> mp,int &ans) {
        if (root == nullptr) return;

        mp[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            int cnt=0;
            for(auto i : mp) if(i.second&1) cnt++;
            if(cnt<=1) ans++;
            return;
        }
        preOrder(root->left, mp,ans);
        preOrder(root->right, mp,ans);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        int ans=0;
        preOrder(root,mp,ans);
        return ans;        
    }
};