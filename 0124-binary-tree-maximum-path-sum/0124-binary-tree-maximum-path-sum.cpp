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
    
    int getPathSum(TreeNode* root,int& pathSum){
        
        if(root == nullptr){
            return 0;
        }

        int leftSubtreePathSum=max(0,getPathSum(root->left,pathSum));
        int rightSubtreePathSum=max(0,getPathSum(root->right,pathSum));
        
        pathSum=max(pathSum,leftSubtreePathSum+rightSubtreePathSum+root->val);
        
        return max(leftSubtreePathSum + root->val,rightSubtreePathSum+root->val);
        
    }
    
    int maxPathSum(TreeNode* root) {
        int pathSum=INT_MIN;
        getPathSum(root,pathSum);
        return pathSum;
        
    }
};