/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void dfsTraversal(TreeNode* root,TreeNode* parent,TreeNode* target,unordered_map<int,pair<bool,pair<TreeNode*,int>>> &umap){
        if(root==NULL){
            return;
        }
        pair<bool,pair<TreeNode*,int>>nodeDetails(false,pair<TreeNode*,int>(parent,(root == target)?0:INT_MAX));
        umap[root->val]=nodeDetails;
        dfsTraversal(root->left,root,target,umap);
        dfsTraversal(root->right,root,target,umap);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //<visited,parent,dist>
        vector<int>nodesAtDistK;
        unordered_map<int,pair<bool,pair<TreeNode*,int>>> umap;
        dfsTraversal(root,NULL,target,umap);
        queue<TreeNode*>qu;
        qu.push(target);
        umap[target->val].first=true;
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                TreeNode* frontNode=qu.front();
                qu.pop();
                if(umap[frontNode->val].second.second == k){
                    nodesAtDistK.push_back(frontNode->val);
                }
                if(frontNode->left!=NULL && umap[frontNode->left->val].first==false){
                    qu.push(frontNode->left);
                    umap[frontNode->left->val].first=true;
                    umap[frontNode->left->val].second.second=umap[frontNode->val].second.second+1;
                }
                if(frontNode->right!=NULL && umap[frontNode->right->val].first==false){
                    qu.push(frontNode->right);
                    umap[frontNode->right->val].first=true;
                    umap[frontNode->right->val].second.second=umap[frontNode->val].second.second+1;
                }
                if(umap[frontNode->val].second.first!=NULL && umap[umap[frontNode->val].second.first->val].first==false){
                    qu.push(umap[frontNode->val].second.first);
                    umap[umap[frontNode->val].second.first->val].first=true;
                    umap[umap[frontNode->val].second.first->val].second.second=umap[frontNode->val].second.second+1;    
                }
            }
        }
        return nodesAtDistK;
    }
};