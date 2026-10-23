/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == nullptr){
            return "";
        }
        
        string leftComputedString=serialize(root->left);
        string rightComputedString=serialize(root->right);
        
        string currSubtreeString=to_string(root->val);
        currSubtreeString+=",";
        currSubtreeString+=(leftComputedString.empty())?"#":leftComputedString;
        currSubtreeString+=",";
        currSubtreeString+=(rightComputedString.empty())?"#":rightComputedString;
        
        return currSubtreeString;
        
    }

    TreeNode* deserializeTree(string data,int& start,int& end){
        
        if(start > end){
            return nullptr;
        }
        
        int tokenStart=start;
        
        while(start<=end && data[start]!=','){
            start++;
        }
        
        string token=data.substr(tokenStart,start-tokenStart);

        if(start<=end){
            start++;
        }
        
        if(token == "#"){
            return nullptr;
        }
        
        TreeNode* root=new TreeNode(stoi(token));
        root->left=deserializeTree(data,start,end);
        root->right=deserializeTree(data,start,end);
        
        return root;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.empty()){
            return nullptr;
        }
        int start=0;
        int end=data.length()-1;
        return deserializeTree(data,start,end);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));