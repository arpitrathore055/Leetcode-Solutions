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
    int maxLevelSum(TreeNode* root) {
        int max=INT_MIN,currLevel=1,smallestLevel=0;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size(),currLevelSum=0;
            for(int i=0;i<size;i++){
                TreeNode* frontNode=qu.front();
                qu.pop();
                currLevelSum+=frontNode->val;
                if(frontNode->left!=NULL){
                    qu.push(frontNode->left);
                }
                if(frontNode->right!=NULL){
                    qu.push(frontNode->right);
                }
            }
            if(currLevelSum>max){
                max=currLevelSum;
                smallestLevel=currLevel;
            }
            currLevel++;
        }
        return smallestLevel;
    }
};