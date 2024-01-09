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

    void inOrder(TreeNode* root,vector<int> &a){
        if(root==NULL) return ;

        inOrder(root->left,a);
        if(root->left==NULL && root->right==NULL) a.push_back(root->val);
        inOrder(root->right,a);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        inOrder(root1,a);
        inOrder(root2,b);
        return a==b;       
    }
};