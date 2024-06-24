class Solution {

    bool isBipartiteGraph=true;

public:

    void dfsTraversal(int source,vector<vector<int>>& graph,vector<pair<bool,int>>& visited,int colour){
        visited[source].first=true;
        visited[source].second=colour;
        for(auto v:graph[source]){
            if(!visited[v].first){
                dfsTraversal(v,graph,visited,(colour==1)?2:1);
            }
            else{
                if(visited[v].second==colour){
                    isBipartiteGraph=false;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<pair<bool,int>> visited(graph.size(),{false,-1});
        for(int i=0;i<graph.size();i++){
            if(!visited[i].first){
                dfsTraversal(i,graph,visited,1);
                if(!isBipartiteGraph){
                    return false;
                }
            }
        }
        return true;
    }
};