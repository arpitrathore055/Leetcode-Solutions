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

    void dfsTraversal(TreeNode* root,int &target,TreeNode* parent){
        if(root==NULL){
            return;
        }
        dfsTraversal(root->left,target,root);
        dfsTraversal(root->right,target,root);
        if(root->left==NULL && root->right==NULL && root->val == target){
            if(parent!=NULL){
                if(parent->left==root){
                    delete(parent->left);
                    parent->left=NULL;
                }
                if(parent->right==root){
                    delete(parent->right);
                    parent->right=NULL;
                }
            }
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfsTraversal(root,target,NULL);
        if(root->left==NULL && root->right==NULL && root->val==target){  
            return NULL;
        }
        return root;
    }
};