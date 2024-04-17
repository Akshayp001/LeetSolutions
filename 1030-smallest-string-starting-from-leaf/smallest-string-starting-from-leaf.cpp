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

    void dfs(TreeNode* root,string &ans,string sol){
        if(root==nullptr) return ;
        sol = (char)('a'+root->val)+sol;
        if(root->left==nullptr && root->right==nullptr){
            if(sol.size()>1){ 
                if(ans==""){
                    ans=sol;
                }else ans=min(sol,ans);
            }
            return;
        }
        dfs(root->left,ans,sol);
        dfs(root->right,ans,sol);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        if(root==nullptr) return ans;
        if(root->left==nullptr  && root->right==nullptr) return ans+(char)('a'+root->val);
        dfs(root,ans,"");
        return ans;
    }
};