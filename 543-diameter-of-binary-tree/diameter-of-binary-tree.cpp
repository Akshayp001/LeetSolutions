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
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+max(height(root->left),height(root->right));
    }

    int dia(TreeNode* root){
        if(root->left==nullptr and root->right==nullptr){
            return 0;
        }
        return height(root->left)+height(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front(); q.pop();
            diameter=max(diameter,dia(t));
            if(t->left!=nullptr) q.push(t->left);
            if(t->right!=nullptr) q.push(t->right);
        }
        return diameter;        
    }
};