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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int k=0;
        while(!q.empty()){
            vector<int> v;
            set<int> st;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* t = q.front(); q.pop();
                if(k&1) {if(t->val&1) return false;}
                else{
                    if(t->val%2==0) return false;
                }
                v.push_back(t->val); st.insert(t->val);
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right); 
            }
            if(st.size()!=v.size()) return false;
            if(k&1){
                vector<int> c=v;
                sort(c.rbegin(),c.rend());
                if(c!=v) return false;
            }else{
                vector<int> c=v;
                sort(c.begin(),c.end());
                if(c!=v) return false;
            }
            k+=1; 
        }
        return true;
    }
};