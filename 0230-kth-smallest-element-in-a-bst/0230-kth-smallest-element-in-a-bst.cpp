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
    
    void dfsTraversal(TreeNode* root,int& currCount,int k,int& kthElement){
        
        if(root == nullptr){
            return;
        }
        
        
        dfsTraversal(root->left,currCount,k,kthElement);
        
        currCount++;
        if(currCount == k){
            kthElement=root->val;   
        }
        
        dfsTraversal(root->right,currCount,k,kthElement);
        
        
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int currCount=0;
        int kthElement=-1;
        dfsTraversal(root,currCount,k,kthElement);
        
        return kthElement;
        
    }
};