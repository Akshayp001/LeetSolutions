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
    
    void solve(TreeNode* root,long long ans,long long &sol){
        if(root==nullptr) return;
        ans= (ans*10) + root->val;
        if(root->left==nullptr && root->right==nullptr){
            sol+= ans;
            return ;
        }
        if(root->left != nullptr) solve(root->left,ans,sol);
        if(root->right != nullptr) solve(root->right,ans,sol);
    }
    int sumNumbers(TreeNode* root) {
        long long sol=0;
        solve(root,0,sol);
        return sol;
    }
};