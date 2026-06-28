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

    unordered_map<TreeNode*,TreeNode*> parentMapping;
    unordered_set<TreeNode*> visitedNodes;

    void dfsForParentMapping(TreeNode* root,TreeNode* parent){

        if(root == nullptr){
            return;
        }
        if(parent != nullptr){
            parentMapping[root]=parent;
        }
        dfsForParentMapping(root->left,root);
        dfsForParentMapping(root->right,root);

    }

    void dfsTraversal(TreeNode* source,int& k,int currDist,vector<int>& nodesAtKDist){

        visitedNodes.insert(source);

        if(currDist == k){
            nodesAtKDist.push_back(source->val);
            return;
        }

        if(source->left != nullptr && !visitedNodes.count(source->left)){
            dfsTraversal(source->left,k,currDist+1,nodesAtKDist);
        }
        if(source->right != nullptr && !visitedNodes.count(source->right)){
            dfsTraversal(source->right,k,currDist+1,nodesAtKDist);
        }
        if(parentMapping.find(source) != parentMapping.end() && !visitedNodes.count(parentMapping[source])){
            dfsTraversal(parentMapping[source],k,currDist+1,nodesAtKDist);
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> nodesAtKDist;
        
        dfsForParentMapping(root,nullptr);
        dfsTraversal(target,k,0,nodesAtKDist);

        return nodesAtKDist;
    }
};