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
    
    void convertBstToGst(TreeNode* root,int &totalSum,int &currSum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            int temp=root->val;
            root->val=totalSum-currSum;
            currSum+=temp;
            return;
        }
        convertBstToGst(root->left,totalSum,currSum);
        int temp=root->val;
        root->val=totalSum-currSum;
        currSum+=temp;
        convertBstToGst(root->right,totalSum,currSum);
    }
    
    int sumOfAllNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        return sumOfAllNodes(root->left)+root->val+sumOfAllNodes(root->right);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int totalSum=sumOfAllNodes(root),currSum=0;
        convertBstToGst(root,totalSum,currSum);
        return root;
    }
};