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
    
    void dfsTraversal(TreeNode* root,string currString,string &smallestString){
        if(root==NULL){
            return;
        }
        currString+=(char)(97+root->val);
        if(root->left==NULL && root->right==NULL){
            if(smallestString == ""){
                smallestString = currString;
            }
            else{
                int sptr1=currString.length()-1,sptr2=smallestString.length()-1;
                bool isSmallAlready=false;
                while(sptr1>=0 && sptr2>=0){
                    if(smallestString[sptr2] < currString[sptr1]){
                        isSmallAlready=true;
                        break;
                    }
                    if(currString[sptr1] < smallestString[sptr2]){
                        smallestString=currString;
                        break;
                    }
                    --sptr1;
                    --sptr2;
                }
                if(!isSmallAlready){
                    smallestString=(sptr1 < 0 && sptr2 >=0)?currString:smallestString;   
                }
            }
            return;
        }
        dfsTraversal(root->left,currString,smallestString);
        dfsTraversal(root->right,currString,smallestString);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string smallestString="",currString="";
        dfsTraversal(root,currString,smallestString);
        reverse(smallestString.begin(),smallestString.end());
        return smallestString;
    }
};