/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>orderList;
        if(root==NULL){
            return orderList;
        }
        vector<int>nodesList;
        queue<Node*>qu;
        qu.push(root);
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                Node* frontNode=qu.front();
                qu.pop();
                nodesList.push_back(frontNode->val);
                for(auto node:frontNode->children){
                    qu.push(node);
                }
            }
            orderList.push_back(nodesList);
            nodesList.clear();
        }
        return orderList;
    }
};