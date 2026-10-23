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

    bool dfsTraversal(TreeNode* root,TreeNode*& prev){

        if(root == nullptr){
            return true;
        }

        bool leftTraversalRes=dfsTraversal(root->left,prev);
        if(!leftTraversalRes){
            return false;
        }

        if(prev != nullptr && root->val <= prev->val){
            return false;
        }
        prev=root;

        bool rightTraversalRes=dfsTraversal(root->right,prev);
        if(!rightTraversalRes){
            return false;
        }

        return true;

    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prevNode=nullptr;
        return dfsTraversal(root,prevNode);
    }

};