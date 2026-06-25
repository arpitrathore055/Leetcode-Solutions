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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> rightnodes;

        if(root == nullptr){
            return rightnodes;
        }

        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){

            int size=qu.size();
            for(int i=0;i<size;i++){

                TreeNode* frontNode=qu.front();
                qu.pop();
                if(i == size-1){
                    rightnodes.push_back(frontNode->val);
                }
                if(frontNode->left != nullptr){
                    qu.push(frontNode->left);
                }
                if(frontNode->right != nullptr){
                    qu.push(frontNode->right);
                }
            }

        }

        return rightnodes;
    }
};