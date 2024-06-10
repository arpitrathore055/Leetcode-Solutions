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

    bool dfsPruningTree(TreeNode* root){
        if(root==NULL){
            return false;
        }
        bool leftPrunedTree=dfsPruningTree(root->left);
        bool rightPrunedTree=dfsPruningTree(root->right);
        if(!leftPrunedTree){
            root->left=NULL;
        }
        if(!rightPrunedTree){
            root->right=NULL;
        }
        return leftPrunedTree || rightPrunedTree || root->val == 1;
    }

    TreeNode* pruneTree(TreeNode* root) {
        return (!dfsPruningTree(root)) ? NULL : root;
    }
};