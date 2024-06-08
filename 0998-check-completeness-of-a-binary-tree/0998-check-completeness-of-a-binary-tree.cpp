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
    bool completeTree=true;
public:

    int countNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return countNodes(root->left) + 1 + countNodes(root->right);
    }

    void dfsTraversal(TreeNode* root,int &countOfNodes,int currInd){
        if(root==NULL){
            return;
        }
        if(currInd>countOfNodes){
            completeTree=false;
            return;
        }
        dfsTraversal(root->left,countOfNodes,(2*currInd));
        dfsTraversal(root->right,countOfNodes,(2*currInd)+1);
    }

    bool isCompleteTree(TreeNode* root) {
        int countOfNodes=countNodes(root);
        dfsTraversal(root,countOfNodes,1);
        return completeTree;
    }
};