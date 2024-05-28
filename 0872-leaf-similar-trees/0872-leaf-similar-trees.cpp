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
    
    void dfsTraversalForSequence(TreeNode* root,vector<int> &seq){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            seq.push_back(root->val);
            return;
        }
        dfsTraversalForSequence(root->left,seq);
        dfsTraversalForSequence(root->right,seq);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>seq1,seq2;
        dfsTraversalForSequence(root1,seq1);
        dfsTraversalForSequence(root2,seq2);
        return (seq1==seq2);
    }
};