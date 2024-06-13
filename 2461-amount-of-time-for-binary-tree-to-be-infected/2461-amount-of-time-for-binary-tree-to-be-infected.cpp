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

    TreeNode* target=NULL;

public:

    void dfsTraversalParent(TreeNode* root,int& start,unordered_map<int,pair<TreeNode*,bool>>&umap,TreeNode* parent){
        if(root==NULL){
            return;
        }
        umap[root->val].first=parent;
        umap[root->val].second=false;
        if(root->val==start){
            target=root;
        }
        dfsTraversalParent(root->left,start,umap,root);
        dfsTraversalParent(root->right,start,umap,root);
    }

    int dfsTraversalMinutes(TreeNode* root,unordered_map<int,pair<TreeNode*,bool>>& umap){
        if(root==NULL){
            return 0;
        }
        umap[root->val].second=true;
        int leftTreeMinutes=0,rightTreeMinutes=0,parentTreeMinutes=0;
        if(root->left!=NULL && umap[root->left->val].second==false){
            leftTreeMinutes=dfsTraversalMinutes(root->left,umap);
        }
        if(root->right!=NULL && umap[root->right->val].second==false){
            rightTreeMinutes=dfsTraversalMinutes(root->right,umap);
        }
        TreeNode* parent=umap[root->val].first;
        bool isParentVisited=(parent==NULL)?false:umap[parent->val].second;
        if(isParentVisited==false){
            parentTreeMinutes=dfsTraversalMinutes(umap[root->val].first,umap);
        }
        return max(leftTreeMinutes,max(rightTreeMinutes,parentTreeMinutes)) +1;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,pair<TreeNode*,bool>> umap;
        dfsTraversalParent(root,start,umap,NULL);
        return dfsTraversalMinutes(target,umap)-1;
    }
};