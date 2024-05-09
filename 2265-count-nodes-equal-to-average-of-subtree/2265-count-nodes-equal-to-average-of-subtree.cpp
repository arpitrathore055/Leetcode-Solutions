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
    
    pair<int,int> countNodes(TreeNode* root,int &nodesCount)
    {
        pair<int,int> ans(0,0);
        if(root==NULL){
            return ans;
        }
        if(root->left==NULL && root->right==NULL){
            ans.first=root->val;
            ans.second=1;
            if((ans.first/ans.second)==root->val){
                nodesCount++;
            }
            return ans;
        }
        pair<int,int> leftCountNodes=countNodes(root->left,nodesCount);
        pair<int,int> rightCountNodes=countNodes(root->right,nodesCount);
        ans.first=leftCountNodes.first+rightCountNodes.first+root->val;
        ans.second=leftCountNodes.second+rightCountNodes.second+1;
        if((ans.first/ans.second)==root->val){
            nodesCount++;
        }
        return ans;
    }
    
    int averageOfSubtree(TreeNode* root) {
        int nodesCount=0;
        pair<int,int> countOfNodes=countNodes(root,nodesCount);
        return nodesCount;
    }
};