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

    void dfsTraversal(TreeNode* root,map<int,int>& map,int level){
        if(root==NULL){
            return;
        }
        if(map.find(level)==map.end()){
            map[level]=root->val;
        }
        dfsTraversal(root->left,map,level+1);
        dfsTraversal(root->right,map,level+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        map<int,int> map;
        dfsTraversal(root,map,0);
        return map[map.size()-1];
    }
};