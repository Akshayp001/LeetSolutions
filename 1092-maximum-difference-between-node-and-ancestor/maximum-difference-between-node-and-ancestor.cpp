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

    // //optimal
    // pair<int,int> minForNodes(TreeNode* root,int &ans){
    //     if(root->left==NULL && root->right==NULL) return {root->val,root->val};

    //     int mini = INT_MAX,maxi = INT_MIN;
    //     if(root->left){
    //         pair<int,int> left = minForNodes(root->left,ans);
    //         mini = min({left.first,mini,root->left->val});
    //         maxi = max({left.second,maxi,root->left->val});
    //     }
    //     if(root->right){
    //         pair<int,int> right = minForNodes(root->right,ans);
    //         mini = min({right.first,mini,root->right->val});
    //         maxi = max({right.second,maxi,root->right->val});
    //     }

    //     ans = max({ans,abs((root->val)-mini),abs((root->val)-maxi)});
    //     return {mini,maxi};
    // }

    // int maxAncestorDiff(TreeNode* root) {
    //     int anss = INT_MIN;
    //     minForNodes(root,anss);
    //     return anss;      
    // }
};