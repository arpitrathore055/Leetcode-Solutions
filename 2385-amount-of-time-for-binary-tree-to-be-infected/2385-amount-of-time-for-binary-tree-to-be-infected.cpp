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

    unordered_map<int,vector<int>> adj;

    void dfsTraversal(TreeNode* root){

        if(root->left != nullptr){

            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfsTraversal(root->left);

        }
        if(root->right != nullptr){
            
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfsTraversal(root->right);

        }

    }

    int amountOfTime(TreeNode* root, int start) {

        dfsTraversal(root);
        int minutes=0;
        queue<int> qu;
        qu.push(start);
        vector<int> visited(100001,false);
        visited[start]=true;
        while(!qu.empty()){

            int size=qu.size();
            for(int i=0;i<size;i++){
                int node=qu.front();
                qu.pop();

                for(auto vertices:adj[node]){
                    if(!visited[vertices]){
                        visited[vertices]=true;
                        qu.push(vertices);
                    }
                }
            }

            minutes++;
        }
        
        return minutes-1;
    }
};