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
    int totalSum=0;
public:
    
    void sumRootToLeaf(TreeNode* root,string &currSum){
        if(root==NULL){
            return;
        }
        currSum+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            totalSum+=stoi(currSum);
            currSum.pop_back();
            return;
        }
        sumRootToLeaf(root->left,currSum);
        sumRootToLeaf(root->right,currSum);
        currSum.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        string currSum="";
        sumRootToLeaf(root,currSum);
        return totalSum;
    }
};