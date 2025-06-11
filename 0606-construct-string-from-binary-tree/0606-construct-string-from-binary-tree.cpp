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

    void solve(string& str,TreeNode* root){
        if(root == nullptr){
            return;
        }
        str+=to_string(root->val);
        if(root->left){
            str+="(";
            solve(str,root->left);
            str+=")";
        }
        if(root->right){
            if(!root->left){
                str+="()";
            }
            str+="(";
            solve(str,root->right);
            str+=")";
        }
    }

    string tree2str(TreeNode* root) {
        
        string str="";
        solve(str,root);
        return str;
    }
};