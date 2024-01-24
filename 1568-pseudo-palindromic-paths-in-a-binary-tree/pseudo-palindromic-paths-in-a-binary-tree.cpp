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

private: 
    bool check(unordered_map<int,int> &m){
        int even=0;
        int odd=0;

        for(auto it:m){
            if((it.second)%2==0)even++;
            else{ odd++;}
        }
        if(odd==0 || odd==1)return true;
        return false;
    }
    void dfs(TreeNode* root, int &paths, unordered_map<int,int> m){

        if(root==NULL)return;
        m[root->val]++;
        if(root->left==NULL && root->right==NULL){
            if(check(m)){
                paths++;
            }
            return ;
        }
        dfs(root->left,paths,m);
        dfs(root->right,paths,m);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int paths=0;
        unordered_map<int,int> m;
        dfs(root, paths,m);
        return paths;  
    }
};