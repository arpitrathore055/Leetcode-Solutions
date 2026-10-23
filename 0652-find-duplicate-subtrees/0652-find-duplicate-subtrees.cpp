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
    
    string dfsTraversal(TreeNode* root,unordered_map<string,int>& stringMap,vector<TreeNode*>& duplicateSubtreeRoots){
        
        if(root == nullptr){
            return "";
        }
        
        string leftComputedString=dfsTraversal(root->left,stringMap,duplicateSubtreeRoots);
        string rightComputedString=dfsTraversal(root->right,stringMap,duplicateSubtreeRoots);
        
        string currSubtreeString=to_string(root->val);
        currSubtreeString+=",";
        currSubtreeString+=(leftComputedString.empty())?"#":leftComputedString;
        currSubtreeString+=",";
        currSubtreeString+=(rightComputedString.empty())?"#":rightComputedString;
        
        stringMap[currSubtreeString]++;
        
        if(stringMap[currSubtreeString] == 2){
            duplicateSubtreeRoots.push_back(root);
        }
        
        return currSubtreeString;

    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string,int> stringMap;
        vector<TreeNode*> duplicateSubtreeRoots;
        
        dfsTraversal(root,stringMap,duplicateSubtreeRoots);
        
        return duplicateSubtreeRoots;
        
    }
};