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
    
    void dfsTraversal(TreeNode* root,int row,int col,map<int,vector<pair<int,int>>>& columnWiseNodes){
        
        if(root == nullptr){
            return;
        }
        
        columnWiseNodes[col].push_back({row,root->val});
        
        dfsTraversal(root->left,row+1,col-1,columnWiseNodes);
        dfsTraversal(root->right,row+1,col+1,columnWiseNodes);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     
        vector<vector<int>> verticalNodesOrdering;
        map<int,vector<pair<int,int>>> columnWiseNodes;
        
        dfsTraversal(root,0,0,columnWiseNodes);
        
        for(auto& entry:columnWiseNodes){
            sort(begin(entry.second),end(entry.second));
            vector<int> temp;
            for(auto& [row,value]:entry.second){
                temp.push_back(value);
            }
            verticalNodesOrdering.push_back(temp);
        }
        
        return verticalNodesOrdering;
        
    }
};