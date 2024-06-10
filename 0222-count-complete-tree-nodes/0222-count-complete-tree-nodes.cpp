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

    int findLeftHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return findLeftHeight(root->left)+1;
    }
    
    int findRightHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return findRightHeight(root->right)+1;
    }

    int countCompleteTreeNodes(TreeNode* root,int level){
        if(root==NULL){
            return 0;
        }
        int leftCTHeight=findLeftHeight(root);
        int rightCTHeight=findRightHeight(root);
        if(leftCTHeight==rightCTHeight){
            return pow(2,leftCTHeight)-1;
        }
        return countCompleteTreeNodes(root->left,level+1) + countCompleteTreeNodes(root->right,level+1) + 1;
    }

    int countNodes(TreeNode* root) {
        return countCompleteTreeNodes(root,0);
    }
};