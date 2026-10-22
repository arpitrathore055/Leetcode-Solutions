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
    
    void dfsTraversal(TreeNode* root,TreeNode*& prevNode,TreeNode*& currInvalidFirstNode,TreeNode*& currInvalidSecondNode,TreeNode*& prevInvalidFirstNode,TreeNode*& prevInvalidSecondNode,int& currInvalidNodeCount){
        
        if(root == nullptr){
            return;
        }
        
        dfsTraversal(root->left,prevNode,currInvalidFirstNode,currInvalidSecondNode,prevInvalidFirstNode,prevInvalidSecondNode,currInvalidNodeCount);
        if(prevNode!= nullptr && root->val <= prevNode->val){
            if(currInvalidNodeCount == 0){
                prevInvalidFirstNode=prevNode;
                currInvalidFirstNode=root;
            }
            else{
                prevInvalidSecondNode=prevNode;
                currInvalidSecondNode=root;
            }
            currInvalidNodeCount++;
        }
        prevNode=root;
        dfsTraversal(root->right,prevNode,currInvalidFirstNode,currInvalidSecondNode,prevInvalidFirstNode,prevInvalidSecondNode,currInvalidNodeCount);
        
    }
    
    void recoverTree(TreeNode* root) {
        
        TreeNode* prevNode=nullptr;
        int currInvalidNodeCount=0;
        TreeNode* prevInvalidFirstNode=nullptr;;
        TreeNode* currInvalidFirstNode=nullptr;;
        TreeNode* prevInvalidSecondNode=nullptr;;
        TreeNode* currInvalidSecondNode=nullptr;;
        dfsTraversal(root,prevNode,currInvalidFirstNode,currInvalidSecondNode,prevInvalidFirstNode,prevInvalidSecondNode,currInvalidNodeCount);
        
        if(prevInvalidSecondNode == nullptr){
            swap(prevInvalidFirstNode->val,currInvalidFirstNode->val);
        }
        else{
            swap(prevInvalidFirstNode->val,currInvalidSecondNode->val);
        }
        
    }
};