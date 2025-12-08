/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == nullptr){
            return node;
        }
        queue<Node*> qu;
        unordered_map<Node*,Node*> mapping;
        vector<bool> visited(101,false);
        qu.push(node);
        visited[node->val]=true;
        while(!qu.empty()){

            int size=qu.size();
            for(int i=0;i<size;i++){

                Node* oldParentNode=qu.front();
                qu.pop();

                //fetched cloned parent node(if not present created a new one)
                Node* clonedParentNode=nullptr;
                if(mapping.find(oldParentNode) != mapping.end()){
                    clonedParentNode=mapping[oldParentNode];
                }
                else{
                    clonedParentNode=new Node(oldParentNode->val);
                    mapping[oldParentNode]=clonedParentNode;
                }

                //traversing over original parent node's neighbours
                for(Node* neighbor:oldParentNode->neighbors){

                    Node* clonedNeighborNode=nullptr;
                    if(mapping.find(neighbor) != mapping.end()){
                        clonedNeighborNode=mapping[neighbor];
                    }
                    else{
                        clonedNeighborNode=new Node(neighbor->val);
                        mapping[neighbor]=clonedNeighborNode;
                    }

                    //addition of neighbors to cloned parent node
                    clonedParentNode->neighbors.push_back(clonedNeighborNode);

                    //addition to queue if not visited
                    if(!visited[neighbor->val]){
                        qu.push(neighbor);
                        visited[neighbor->val]=true;
                    }

                }

            }

        }

        return mapping[node];

    }
};