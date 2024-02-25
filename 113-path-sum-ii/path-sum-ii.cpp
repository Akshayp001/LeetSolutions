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
    vector<vector<int>> sol;
    int target;
    void solve(TreeNode* root,vector<int> ans,int sum){
        if(root==nullptr) return;
        ans.push_back(root->val);
        sum+=root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(sum==target) sol.push_back(ans);
            return;
        }
        solve(root->left,ans,sum);        
        solve(root->right,ans,sum);        
        ans.pop_back();
        sum-=root->val;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        solve(root,{},0);
        return sol;        
    }
};