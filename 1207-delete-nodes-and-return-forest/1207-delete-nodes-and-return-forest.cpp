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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>uset;
        for(auto targetNodeValue:to_delete){
            uset.insert(targetNodeValue);
        }
        vector<TreeNode*> rootList;
        queue<pair<TreeNode*,TreeNode*>>qu;
        pair<TreeNode*,TreeNode*>p;
        p.first=root;
        p.second=NULL;
        qu.push(p);
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                bool toDeleteNode=false;
                pair<TreeNode*,TreeNode*> frontNode=qu.front();
                qu.pop();
                if(uset.find(frontNode.first->val)!=uset.end()){
                    toDeleteNode=true;
                    if(frontNode.second!=NULL){
                        TreeNode* parentNode=frontNode.second;
                        if(parentNode->left == frontNode.first){
                            parentNode->left=NULL;
                        }
                        if(parentNode->right == frontNode.first){
                            parentNode->right=NULL;
                        }
                    }
                }
                if(!toDeleteNode && frontNode.second==NULL){
                    rootList.push_back(frontNode.first);
                }
                if(frontNode.first->left!=NULL){
                    pair<TreeNode*,TreeNode*>tmp;
                    tmp.first=frontNode.first->left;
                    tmp.second=(toDeleteNode) ? NULL:frontNode.first;
                    qu.push(tmp);
                }
                if(frontNode.first->right!=NULL){        
                    pair<TreeNode*,TreeNode*>tmp;
                    tmp.first=frontNode.first->right;
                    tmp.second=(toDeleteNode) ? NULL:frontNode.first;
                    qu.push(tmp);
                }
                if(toDeleteNode){
                    delete(frontNode.first);
                }
            }
        }
        return rootList;
    }
};