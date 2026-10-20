/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
       if(root == nullptr || root == p || root == q){
        return root;
       }
       
       TreeNode* leftSideLCA=lowestCommonAncestor(root->left,p,q);
       TreeNode* rightSizeLCA=lowestCommonAncestor(root->right,p,q);
       
       if(leftSideLCA != nullptr && rightSizeLCA != nullptr){
        return root;
       }
       
       return (leftSideLCA != nullptr)?leftSideLCA:rightSizeLCA;
              
    }
};