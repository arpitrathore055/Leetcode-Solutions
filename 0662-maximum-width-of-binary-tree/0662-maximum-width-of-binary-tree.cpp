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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int width=0;
        queue<pair<TreeNode*,int>>qu;
        qu.push({root,0});
        while(!qu.empty()){
            int size=qu.size(),startInd=qu.front().second,endInd=qu.back().second;
            for(int i=0;i<size;i++){
                pair<TreeNode*,long> frontNode=qu.front();
                qu.pop();
                if(frontNode.first->left!=NULL){
                    qu.push({frontNode.first->left,(2 * frontNode.second) + 1});
                }
                if(frontNode.first->right!=NULL){
                    qu.push({frontNode.first->right,2 * frontNode.second + 2});
                }
            }
            if(width < (endInd-startInd+1)){
                width = (endInd-startInd)+1;
            }
        }
        return width;
    }
};