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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>levelList;
        if(root==NULL){
            return levelList;
        }
        queue<TreeNode*>qu;
        qu.push(root);
        vector<int>temp;
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                TreeNode* frontNode=qu.front();
                qu.pop();
                temp.push_back(frontNode->val);
                if(frontNode->left!=NULL){
                    qu.push(frontNode->left);
                }
                if(frontNode->right!=NULL){
                    qu.push(frontNode->right);
                }
            }
            levelList.push_back(temp);
            temp.clear();
        }
        reverse(levelList.begin(),levelList.end());
        return levelList;
    }
};