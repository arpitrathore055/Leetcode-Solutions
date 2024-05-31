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
    int totalGoodNodes=0;
public:
    
    void dfsTraversal(TreeNode* root,priority_queue<int> &maxValue){
        if(root==NULL){
            return;
        }
        if(maxValue.empty() || maxValue.top() <= root->val){
            ++totalGoodNodes;
            maxValue.push(root->val);
        }
        dfsTraversal(root->left,maxValue);
        dfsTraversal(root->right,maxValue);
        if(root->val == maxValue.top()){
            maxValue.pop();
        }
    }
    
    int goodNodes(TreeNode* root) {
        priority_queue<int>maxValue;
        dfsTraversal(root,maxValue);
        return totalGoodNodes;
    }
};