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
    int c=0,kk;
    void inorder(TreeNode* root,int &ans){
        if(root==nullptr) return ;
        if(root->left!=nullptr)  inorder(root->left,ans);
        c++;
        if(c==kk){
            ans=root->val;
        }
        if(root->right!=nullptr)  inorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        kk=k;c=0;
        int ans=root->val;
        inorder(root,ans);
        return ans;       
    }
};