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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int leftMinDepth=minDepth(root->left);
        int rightMinDepth=minDepth(root->right);
        if(leftMinDepth==0 && rightMinDepth!=0 || leftMinDepth!=0 && rightMinDepth==0){
            return (leftMinDepth==0) ? rightMinDepth + 1: leftMinDepth + 1;
        }
        return min(leftMinDepth,rightMinDepth)+1;
    }
};