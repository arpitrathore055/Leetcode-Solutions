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
    
    
    void dfsTraversal(TreeNode* root,int targetSum,int& pathCount,long long& currSum,unordered_map<long long,int>& prefix){
        
        //basecase
        if(root == nullptr){
            return;
        }
        
        currSum+=root->val;
        long long targetPrefix=currSum-targetSum;
        
        if(prefix.find(targetPrefix) != prefix.end()){
            pathCount+=prefix[targetPrefix];
        }   
        prefix[currSum]++;
        
        dfsTraversal(root->left,targetSum,pathCount,currSum,prefix);
        dfsTraversal(root->right,targetSum,pathCount,currSum,prefix);
        
        prefix[currSum]--;
        currSum-=root->val;         
        
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        
        int pathCount=0;
        long long currSum=0;
        unordered_map<long long,int> prefix;
        prefix[0]=1;
        dfsTraversal(root,targetSum,pathCount,currSum,prefix);
        return pathCount;
        
    }
};