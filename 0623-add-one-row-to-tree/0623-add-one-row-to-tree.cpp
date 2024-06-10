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

    void dfsTraversal(TreeNode* root,int &val,int &depth,int currDepth){
        if(root==NULL){
            return;
        }
        if(currDepth==depth-1){
            TreeNode* newLeftNode=new TreeNode(val);
            TreeNode* newRightNode=new TreeNode(val);
            newLeftNode->left=root->left;
            root->left=newLeftNode;
            newRightNode->right=root->right;
            root->right=newRightNode;
        }
        dfsTraversal(root->left,val,depth,currDepth+1);
        dfsTraversal(root->right,val,depth,currDepth+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        dfsTraversal(root,val,depth,1);
        return root;
    }
};