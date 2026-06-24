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
    
    pair<int,int> dfs(TreeNode* root){
        
        if(root == nullptr){
            return {0,0};
        }
        
        auto leftCompute=dfs(root->left);
        auto rightCompute=dfs(root->right);
        
        //computing for not robbing root
        int notTake=max(leftCompute.first,leftCompute.second) + max(rightCompute.first,rightCompute.second);
        
        //computing for robbing root
        int take=root->val + leftCompute.first + rightCompute.first; 
        
        return {notTake,take};
    }
    
    int rob(TreeNode* root) {
  
        pair<int,int> maxRobbedValue=dfs(root);
  
        return max(maxRobbedValue.first,maxRobbedValue.second);
    }
};