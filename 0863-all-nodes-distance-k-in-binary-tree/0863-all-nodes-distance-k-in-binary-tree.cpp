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
    
    void dfsTraversal(TreeNode* root,TreeNode* parent,unordered_map<int,TreeNode*>& parentMapping){
    
        if(root == nullptr){
            return;
        }
        
        if(parent != nullptr){
            parentMapping[root->val]=parent;
        }
        
        dfsTraversal(root->left,root,parentMapping);
        dfsTraversal(root->right,root,parentMapping);
        
    }
    
    void dfsTraversal(TreeNode* target,int currLevel,int k,unordered_set<int>& visited,unordered_map<int,TreeNode*>& parentMapping,vector<int>& kDistNodes){
        
        visited.insert(target->val);
        
        if(currLevel == k){
            kDistNodes.push_back(target->val);
            return;
        }
        
        //left
        if(target->left != nullptr && visited.find(target->left->val) == visited.end()){
            dfsTraversal(target->left,currLevel+1,k,visited,parentMapping,kDistNodes);
        }
        
        //right
        if(target->right != nullptr && visited.find(target->right->val) == visited.end()){
            dfsTraversal(target->right,currLevel+1,k,visited,parentMapping,kDistNodes);
        }
        
        //parent
        if(parentMapping.find(target->val) != parentMapping.end() && visited.find(parentMapping[target->val]->val) == visited.end()){
            dfsTraversal(parentMapping[target->val],currLevel+1,k,visited,parentMapping,kDistNodes);
        }
        
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> kDistNodes;
        unordered_map<int,TreeNode*> parentMapping;
        unordered_set<int> visited;
        
        dfsTraversal(root,nullptr,parentMapping);
        dfsTraversal(target,0,k,visited,parentMapping,kDistNodes);
              
        return kDistNodes;
        
    }
};