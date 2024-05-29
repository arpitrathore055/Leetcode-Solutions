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
    
    void dfsTraversal(TreeNode* root,int &currLevel,map<int,int>&umap){
        if(root==NULL){
            return;
        }
        umap[currLevel]+=root->val;
        if(root->left!=NULL){
            dfsTraversal(root->left,++currLevel,umap);    
        }
        if(root->right!=NULL){
            dfsTraversal(root->right,++currLevel,umap);    
        }
        --currLevel;
    }
    
    int maxLevelSum(TreeNode* root) {
        map<int,int>umap;
        int currLevel=1,maxSum=INT_MIN,maxSumLevel=1;
        dfsTraversal(root,currLevel,umap);
        for(auto ele:umap){
            if(ele.second>maxSum){
                maxSum=ele.second;
                maxSumLevel=ele.first;
            }
        }
        return maxSumLevel;
    }
};