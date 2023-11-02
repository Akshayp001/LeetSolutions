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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        int maxWidth=0;
        q.push({root,0});
        while(!q.empty()){
            int first,last;
            int size = q.size();
            unsigned long long itr = q.front().second;
            for(int i=0;i<size;i++){
                unsigned long long curr = q.front().second-itr;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first=curr;
                if(i==size-1) last=curr;
                if(node->left) q.push({node->left,curr*2+1});
                if(node->right) q.push({node->right,curr*2+2});
            }
            maxWidth = max(maxWidth,last-first+1);
        }
        return maxWidth; 
    }
};