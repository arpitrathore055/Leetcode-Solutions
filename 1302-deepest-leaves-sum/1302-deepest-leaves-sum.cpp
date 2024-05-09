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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum=0;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            sum=0;
            int sizeOfQueue=qu.size();
            for(int i=0;i<sizeOfQueue;i++){
                TreeNode* frontNode=qu.front();
                sum+=frontNode->val;
                qu.pop();
                if(frontNode->left!=NULL){
                    qu.push(frontNode->left);
                }
                if(frontNode->right!=NULL){
                    qu.push(frontNode->right);
                }
            }
        }
        return sum;
    }
};