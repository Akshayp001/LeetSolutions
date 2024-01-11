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

    void checkmini(TreeNode* root,int &mini,int parent){
        if(root==NULL) return;
        
        checkmini(root->left,mini,parent);
        if(root->val!=parent) mini = max(mini,abs(parent-(root->val)));
        checkmini(root->right,mini,parent);
    }

    void io(TreeNode* root,int &mini){
        if(root==NULL) return;

        io(root->left,mini);
        checkmini(root,mini,root->val);
        io(root->right,mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini = 0;
        io(root,mini);  
        return mini;      
    }
};