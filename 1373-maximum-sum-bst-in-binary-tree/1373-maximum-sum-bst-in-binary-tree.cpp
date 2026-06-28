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

    int ans;

    tuple<bool,int,int,int> solve(TreeNode* root){

        //basecase
        if(root == nullptr){
            return {true,0,INT_MAX,INT_MIN};
        }

        tuple<bool,int,int,int> left_child_ans=solve(root->left);
        tuple<bool,int,int,int> right_child_ans=solve(root->right);

        if(get<0>(left_child_ans) && get<0>(right_child_ans) && get<3>(left_child_ans) < root->val && get<2>(right_child_ans) > root->val){
            int computedAns=get<1>(left_child_ans) + get<1>(right_child_ans) + root->val;
            ans=max(ans,computedAns);
            return {true,computedAns,min(root->val,get<2>(left_child_ans)),max(root->val,get<3>(right_child_ans))};
        }
        return {false,0,INT_MAX,INT_MIN};
    }

    int maxSumBST(TreeNode* root) {
        
        tuple<bool,int,int,int> answer=solve(root);
        //isBST,subtree sum,subtree min,subtree max
        return ans;
    }
};