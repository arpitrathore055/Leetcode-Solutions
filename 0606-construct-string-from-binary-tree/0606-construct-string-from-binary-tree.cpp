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

    string solve(string str,TreeNode* root){

        if(root ==nullptr){
            return "";
        }
        if(root->left ==nullptr && root->right ==nullptr){
            return to_string(root->val);
        }

        string leftStr=solve(str,root->left);
        string rightStr=solve(str,root->right);
        if(leftStr.length()==0 && rightStr.length()!=0 || leftStr.length()!=0 && rightStr.length()!=0){
            return to_string(root->val)+"("+leftStr+")"+"("+rightStr+")";
        }
        return to_string(root->val)+"("+leftStr+")"+rightStr;
    }

    string tree2str(TreeNode* root) {
        string str="";
        return solve(str,root);
    }
};