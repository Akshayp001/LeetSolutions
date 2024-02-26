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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
    // int m = -(1e4 +1);
    // TreeNode* mm = new TreeNode(m);
    // queue<TreeNode*> q1;
    // queue<TreeNode*> q2;
    // vector<int> v1;
    // vector<int> v2;
    // q1.push(p);
    // q2.push(q);
    // while (!q1.empty()){
    //     TreeNode* temp = q1.front();
    //     q1.pop();
    //     if(temp->val!=m){
    //         if(temp->left!=NULL) q1.push(temp->left);
    //         if(temp->right!=NULL) q1.push(temp->right);
    //         if(temp->left==NULL) q1.push(mm);
    //         if(temp->right==NULL) q1.push(mm);
    //     }
    //     v1.push_back(temp->val);
    // }
    // while (!q2.empty()){
    //     TreeNode* temp = q2.front();
    //     q2.pop();
    //     if(temp->val!=m){
    //         if(temp->left!=NULL) q2.push(temp->left);
    //         if(temp->right!=NULL) q2.push(temp->right);
    //         if(temp->left==NULL) q2.push(mm);
    //         if(temp->right==NULL) q2.push(mm);
    //     }
    //     v2.push_back(temp->val);
    // }
    // return v1==v2; 


      if(r1==NULL && r2==NULL) return true;

      if(r1==NULL || r2==NULL) return false;

      if(r1->val!=r2->val) return false;

      bool leftSubTree = isSameTree(r1->left,r2->left);
      bool rightSubTree= isSameTree(r1->right,r2->right);

      return leftSubTree && rightSubTree; 
    }
};