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
    
    pair<int,int> dfsTraversal(TreeNode* root){

        if(root == nullptr){
            return {0,0};
        }

        pair<int,int> maxRobbedValueLeft=dfsTraversal(root->left);
        pair<int,int> maxRobbedValueRight=dfsTraversal(root->right);
        
        //computing for root not taken/robbed
        int notRobbed=max(maxRobbedValueLeft.first,maxRobbedValueLeft.second) + max(maxRobbedValueRight.first,maxRobbedValueRight.second);

        //computing for root take/robbed
        int robbed=root->val + maxRobbedValueLeft.first + maxRobbedValueRight.first;
        
        return {notRobbed,robbed};
        
    }
    
    int rob(TreeNode* root) {
     
        //pair<root not taken,root taken>
        pair<int,int> maxRobbedValue=dfsTraversal(root);
        return max(maxRobbedValue.first,maxRobbedValue.second);
        
    }
};