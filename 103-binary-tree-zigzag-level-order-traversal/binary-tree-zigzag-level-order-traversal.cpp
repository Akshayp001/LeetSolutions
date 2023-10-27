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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> sol;
    if(root==NULL) return {};
    q.push(root);
    int count = 0;
    while (!q.empty()){
        int size = q.size();
        vector<int> ans;
        count++;
        for(int i=0;i<size;i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            ans.push_back(temp->val);     
        }
        cout<<count<<endl;
        if(count%2==0) reverse(ans.begin(),ans.end());
        sol.push_back(ans);
    }
    return sol;
    
    }
};