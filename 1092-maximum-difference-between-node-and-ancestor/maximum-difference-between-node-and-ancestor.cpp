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

    //brute force 

    // void checkmini(TreeNode* root,int &mini,int parent){
    //     if(root==NULL) return;
        
    //     checkmini(root->left,mini,parent);
    //     if(root->val!=parent) mini = max(mini,abs(parent-(root->val)));
    //     checkmini(root->right,mini,parent);
    // }

    // void io(TreeNode* root,int &mini){
    //     if(root==NULL) return;

    //     io(root->left,mini);
    //     checkmini(root,mini,root->val);
    //     io(root->right,mini);
    // }
    // int maxAncestorDiff(TreeNode* root) {
    //     int mini = 0;
    //     io(root,mini);  
    //     return mini;      
    // }

    //optimal
    pair<int,int> minForNodes(TreeNode* root,vector<vector<int>> &pairs){
        if(root->left==NULL && root->right==NULL) return {root->val,root->val};
        int mini = INT_MAX;
        int maxi = INT_MIN;
        if(root->left){
            pair<int,int> left = minForNodes(root->left,pairs);
            mini = min({left.first,mini,root->left->val});
            maxi = max({left.second,maxi,root->left->val});
        }
        if(root->right){
            pair<int,int> right = minForNodes(root->right,pairs);
            mini = min({right.first,mini,root->right->val});
            maxi = max({right.second,maxi,root->right->val});
        }

        pairs.push_back({root->val,mini,maxi});
        return {mini,maxi};
    }

    int maxAncestorDiff(TreeNode* root) {
        vector<vector<int>> pairs;
        minForNodes(root,pairs);
        int ans = 0;
        for(auto pair:pairs){
            ans = max({ans,abs(pair[0]-pair[1]),abs(pair[0]-pair[2])});        
        }
        return ans;      
    }
};