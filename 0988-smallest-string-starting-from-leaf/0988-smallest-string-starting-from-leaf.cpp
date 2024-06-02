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
    string smallestFromLeaf(TreeNode* root) {
        string smallestString="";
        queue<pair<TreeNode*,string>>qu;
        pair<TreeNode*,string>p;
        p.first=root;
        p.second=(char)(97+root->val);
        qu.push(p);
        while(!qu.empty()){
            int size=qu.size();
            pair<TreeNode*,string>tmp;
            for(int i=0;i<size;i++){
                pair<TreeNode*,string>frontNodePair=qu.front();
                qu.pop();
                if(frontNodePair.first->left!=NULL){
                    tmp.first=frontNodePair.first->left;
                    tmp.second=(char)(97+frontNodePair.first->left->val)+frontNodePair.second;
                    qu.push(tmp);
                }
                if(frontNodePair.first->right!=NULL){
                    tmp.first=frontNodePair.first->right;
                    tmp.second=(char)(97+frontNodePair.first->right->val)+frontNodePair.second;
                    qu.push(tmp);
                }
                if(frontNodePair.first->left==NULL && frontNodePair.first->right==NULL){
                    if(smallestString==""){
                        smallestString = frontNodePair.second;
                    }
                    else{
                        smallestString=min(smallestString,frontNodePair.second);
                    }
                }
            }
        }
        return smallestString;
    }
};