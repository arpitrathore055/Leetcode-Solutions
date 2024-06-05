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
    TreeNode* nodeContainingDeepestNode=NULL;
    int maxDepth=INT_MIN;
public:

    pair<int,int> subTreeContainingDeepestNodes(TreeNode* root,int currDepth){
        if(root==NULL){
            return {0,-1};
        }
        if(root->left==NULL && root->right==NULL){
            pair<int,int> rootPair;
            rootPair.first=root->val;
            rootPair.second=currDepth;
            if(maxDepth < currDepth){
                maxDepth=currDepth;
                nodeContainingDeepestNode=root;
            }
            return rootPair;
        }
        ++currDepth;
        pair<int,int> leftSubTreeNode=subTreeContainingDeepestNodes(root->left,currDepth);
        pair<int,int> rightSubTreeNode=subTreeContainingDeepestNodes(root->right,currDepth);
        if(leftSubTreeNode.second == rightSubTreeNode.second){
            if(leftSubTreeNode.second >= maxDepth){
                nodeContainingDeepestNode=root;
            }
            return leftSubTreeNode;
        }
        return (leftSubTreeNode.second > rightSubTreeNode.second) ? leftSubTreeNode : rightSubTreeNode;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int,int> traversalPair=subTreeContainingDeepestNodes(root,0);
        return nodeContainingDeepestNode;
    }
};