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

    tuple<bool,long long,long long> validBST(TreeNode* root){
        //basecase
        if(root == nullptr){
            return {true,LLONG_MAX,LLONG_MIN};
        }

        tuple<bool,long long,long long> left_child_ans=validBST(root->left);
        tuple<bool,long long,long long> right_child_ans=validBST(root->right);

        if(get<0>(left_child_ans) && get<0>(right_child_ans)){
            //checking for validity
            long long left_child_max=get<2>(left_child_ans);
            long long right_child_min=get<1>(right_child_ans);
            long long value=root->val;
            if(left_child_max < root->val && right_child_min > root->val){
                return {true,min(get<1>(left_child_ans),value),max(get<2>(right_child_ans),value)};
            }
        }
        return {false,LLONG_MAX,LLONG_MIN};
    }

    bool isValidBST(TreeNode* root) {
        //isBST,minInBST,maxInBST
        tuple<bool,long long,long long> ans=validBST(root);
        return get<0>(ans);
    }
};