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

    void inOrder(TreeNode* root,int &sum,int l,int h){
        if(root==NULL) return;

        inOrder(root->left,sum,l,h);
        if(root->val>=l && root->val<=h)sum+=root->val;
        inOrder(root->right,sum,l,h);

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        inOrder(root,sum,low,high);
    return sum;
        
    }
};