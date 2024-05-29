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
    vector<int> largestValues(TreeNode* root) {
        vector<int>valueList;
        int maxVal=0;
        if(root==NULL){
            return valueList;
        }
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            maxVal=INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* frontNode=qu.front();
                qu.pop();
                if(frontNode->val > maxVal){
                    maxVal=frontNode->val;
                }
                if(frontNode->left!=NULL){
                    qu.push(frontNode->left);
                }
                if(frontNode->right!=NULL){
                    qu.push(frontNode->right);
                }
            }
            valueList.push_back(maxVal);
        }
        return valueList;
    }
};