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
    TreeNode* target=NULL;
public:

    void dfsTraversal(TreeNode* root,int& start,unordered_map<int,pair<TreeNode*,bool>>& umap,TreeNode* parent){
        if(root==NULL){
            return;
        }
        umap[root->val].first=parent;
        umap[root->val].second=false;
        if(root->val==start){
            target=root;
        }
        dfsTraversal(root->left,start,umap,root);
        dfsTraversal(root->right,start,umap,root);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,pair<TreeNode*,bool>> umap;
        dfsTraversal(root,start,umap,NULL);
        queue<TreeNode*>qu;
        int minutes=0;
        qu.push(target);
        umap[target->val].second=true;
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                TreeNode* frontNode=qu.front();
                qu.pop();
                if(frontNode->left!=NULL && umap[frontNode->left->val].second==false){
                    umap[frontNode->left->val].second=true;
                    qu.push(frontNode->left);
                }
                if(frontNode->right!=NULL && umap[frontNode->right->val].second==false){
                    umap[frontNode->right->val].second=true;
                    qu.push(frontNode->right);
                }
                TreeNode* parent=umap[frontNode->val].first;
                bool isParentVisited=(parent==NULL)? false : umap[parent->val].second;
                if(parent!=NULL && isParentVisited==false){
                    umap[parent->val].second=true;
                    qu.push(parent);
                }
            }
            ++minutes;
        }
        return minutes-1;
    }   
};