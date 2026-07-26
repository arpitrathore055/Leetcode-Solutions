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

    int maxSumAchieved=INT_MIN;

    int solve(TreeNode* root){

        if(root == nullptr){
            return 0;
        }

        int leftMaxPath=solve(root->left);
        int rightMaxPath=solve(root->right);

        maxSumAchieved=max(maxSumAchieved,max(0,leftMaxPath) + root->val + max(0,rightMaxPath));
        return root->val + max(0,max(leftMaxPath,rightMaxPath));

    }

    int maxPathSum(TreeNode* root) {

        solve(root);
        return maxSumAchieved;

    }
};
