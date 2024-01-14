#include <iostream>
#include <climits>
#include <algorithm>

class Solution {
public:
    int maxSum;

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Info findMaxBST(TreeNode* root) {
        if (root == nullptr) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info leftInfo = findMaxBST(root->left);
        Info rightInfo = findMaxBST(root->right);

        if (leftInfo.isBST && rightInfo.isBST && root->val > leftInfo.maxVal && root->val < rightInfo.minVal) {
            int totalSum = root->val + leftInfo.sum + rightInfo.sum;
            maxSum = max(maxSum, totalSum);
            int minVal = min(root->val, leftInfo.minVal);
            int maxVal = max(root->val, rightInfo.maxVal);
            return {true, totalSum, minVal, maxVal};
        } else {
            return {false, 0, 0, 0};
        }
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        findMaxBST(root);
        return maxSum;
    }
};
