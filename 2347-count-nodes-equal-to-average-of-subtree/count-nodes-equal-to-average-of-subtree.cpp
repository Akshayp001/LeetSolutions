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
    void preOrder(TreeNode* root,int &sum,int &nnodes){
        if(root==NULL) return;
        sum+=root->val;
        nnodes+=1;
        preOrder(root->left,sum,nnodes);
        preOrder(root->right,sum,nnodes);
    }

    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root==NULL) return 0;
        int count=0;

        q.push(root);
        while(!q.empty()){
            int sum=0;
            int nn=0;
            TreeNode* temp = q.front();
            q.pop();
            preOrder(temp,sum,nn);
            int avg = sum/nn;
            if(avg==temp->val) count++;
            if(temp->left) q.push(temp->left); 
            if(temp->right) q.push(temp->right); 
        }
        
        
        return count;

        
    }
};