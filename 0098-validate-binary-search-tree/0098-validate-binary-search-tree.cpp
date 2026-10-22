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
    
    bool dfsTraversal(TreeNode* root,TreeNode*& prevNode){
        
        if(root == nullptr){
            return true;
        }
        
        bool isValidLeft=dfsTraversal(root->left,prevNode);
        
        if(!isValidLeft){
            return false;
        }
        
        if(prevNode != nullptr && root->val <= prevNode->val){
            return false;    
        }
        prevNode=root;
        
        bool isValidRight=dfsTraversal(root->right,prevNode);
        
        if(!isValidRight){
            return false;
        }
        
        return true;
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        TreeNode* prevNode=nullptr;
        return dfsTraversal(root,prevNode);

    }
};