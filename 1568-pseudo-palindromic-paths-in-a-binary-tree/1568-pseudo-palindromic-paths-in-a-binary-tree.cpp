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

    int count=0;

public:

    void dfsTraversal(TreeNode* root,unordered_map<int,int>& umap){
        if(root==NULL){
            return;
        }
        umap[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int countEvenValueNodes=0,countOddValueNodes=0;
            for(auto node:umap){
                if((node.second%2)==0){
                    countEvenValueNodes++;
                }
                else{
                    countOddValueNodes++;
                }
            }
            if(countEvenValueNodes==umap.size() || countEvenValueNodes==umap.size()-1){
                count++;
            }
        }
        dfsTraversal(root->left,umap);
        dfsTraversal(root->right,umap);
        umap[root->val]--;
        if(umap[root->val]<=0){
            umap.erase(root->val);
        }
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> umap;
        dfsTraversal(root,umap);
        return count;
    }
};