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
    
    TreeNode* buildTreeUsingTraversal(vector<int>& preorder,vector<int>& inorder,int preorderStart,int inorderStart,int inorderEnd){
        
        if(inorderStart > inorderEnd || preorderStart >= preorder.size()){
            return nullptr;
        }
        
        TreeNode* rootNode=new TreeNode(preorder[preorderStart]);
        
        int rootPositionInorder=inorderStart;
        for(int i=inorderStart;i<=inorderEnd;i++){
            if(inorder[i] == preorder[preorderStart]){
                rootPositionInorder=i;
                break;
            }
        }
        
        int leftSubtreeNodesCount=rootPositionInorder-inorderStart;
        int rightSubtreeNodesCount=inorderEnd-rootPositionInorder;
        
        TreeNode* leftSubtreeRoot=buildTreeUsingTraversal(preorder,inorder,preorderStart+1,inorderStart,rootPositionInorder-1);
        TreeNode* rightSubtreeRoot=buildTreeUsingTraversal(preorder,inorder,preorderStart+leftSubtreeNodesCount+1,rootPositionInorder+1,inorderEnd);
        
        rootNode->left=leftSubtreeRoot;
        rootNode->right=rightSubtreeRoot;
        
        return rootNode;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
        return buildTreeUsingTraversal(preorder,inorder,0,0,n-1);
              
    }   

};