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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int level=1;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                TreeNode* frontNode=qu.front();
                qu.pop();
                if(frontNode->left==NULL && frontNode->right==NULL){
                    return level;
                }
                if(frontNode->left!=NULL){
                    qu.push(frontNode->left);
                }
                if(frontNode->right!=NULL){
                    qu.push(frontNode->right);
                }
            }
            ++level;
        }
        return level;
    }
};