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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> zigzagorder;
        
        if(root == nullptr){
            return zigzagorder;
        }
        
        queue<TreeNode*> qu;
        qu.push(root);
        bool leftToRight=true;
        while(!qu.empty()){
            
            int size=qu.size();
            vector<int> levelorderlist(size);
            for(int i=0;i<size;i++){
                
                TreeNode* frontNode=qu.front();
                qu.pop();
                
                int index=(leftToRight)?i:size-1-i;
                levelorderlist[index]=frontNode->val;
                
                if(frontNode->left != nullptr){
                    qu.push(frontNode->left);
                }
                if(frontNode->right != nullptr){
                    qu.push(frontNode->right);
                }
                
            }
            zigzagorder.push_back(levelorderlist);
            leftToRight=!leftToRight;
        }
        
        return zigzagorder;
    }
};