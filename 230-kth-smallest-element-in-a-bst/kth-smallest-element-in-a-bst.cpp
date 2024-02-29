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
    int kk,ans;
    void inorder(TreeNode* root){
        if(root==nullptr) return ;
        if(root->left!=nullptr)  inorder(root->left);
        kk--;
        if(0==kk){
            ans=root->val; return;
        }
        if(root->right!=nullptr)  inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        kk=k;
        inorder(root);
        return ans;       
    }
};