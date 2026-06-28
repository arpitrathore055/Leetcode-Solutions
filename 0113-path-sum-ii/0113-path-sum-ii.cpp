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
    
    void backtrack(TreeNode* root,int targetSum,vector<int>& currPath,vector<vector<int>>& pathCollections){
       
       //basecase
       if(root == nullptr){
        return;
       }
        
       if(root->left == nullptr && root->right == nullptr && targetSum - root->val == 0){
            currPath.push_back(root->val);
            pathCollections.push_back(currPath);
            currPath.pop_back();
            return;
       }

       //apply
       currPath.push_back(root->val);

       if(root->left != nullptr){
        backtrack(root->left,targetSum - (root->val),currPath,pathCollections);
       }
       if(root->right != nullptr){
        backtrack(root->right,targetSum - (root->val),currPath,pathCollections);
       }

       currPath.pop_back();

    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> pathCollections;
        vector<int> currPath;
        
        backtrack(root,targetSum,currPath,pathCollections);
        
        return pathCollections;

    }
};