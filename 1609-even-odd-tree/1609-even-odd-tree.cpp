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
    bool isEvenOddTree(TreeNode* root) {
        bool isStrictlyIncreasing=true;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                TreeNode* frontNode=qu.front();
                if(isStrictlyIncreasing && (frontNode->val%2)!=0 || !isStrictlyIncreasing && (frontNode->val%2)==0){
                    qu.pop();
                    if(i!=size-1){
                        if(!qu.empty() && isStrictlyIncreasing && frontNode->val >= qu.front()->val || !qu.empty() && !isStrictlyIncreasing && frontNode->val <= qu.front()->val){
                            return false;
                        }
                    }
                    if(frontNode->left!=NULL){
                        qu.push(frontNode->left);
                    }
                    if(frontNode->right!=NULL){
                        qu.push(frontNode->right);
                    }
                }
                else{
                    return false;
                }
            }
            isStrictlyIncreasing=!isStrictlyIncreasing;
        }
        return true;
    }
};