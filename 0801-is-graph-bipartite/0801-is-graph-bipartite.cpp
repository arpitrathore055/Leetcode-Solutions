class Solution {

    bool isBipartiteGraph=true;

public:

    void bfsTraversal(int source,vector<vector<int>>& graph,vector<pair<bool,int>>& visited){
        queue<int>qu;
        visited[source].first=true;
        visited[source].second=1;
        qu.push(source);
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                int frontVertex=qu.front();
                qu.pop();
                for(auto v:graph[frontVertex]){
                    if(!visited[v].first){
                        visited[v].first=true;
                        visited[v].second=(visited[frontVertex].second==1)?2:1;
                        qu.push(v);
                    }
                    else{
                        if(visited[v].second == visited[frontVertex].second){
                            isBipartiteGraph=false;
                        }
                    }
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<pair<bool,int>> visited(graph.size(),{false,-1});
        for(int i=0;i<graph.size();i++){
            if(!visited[i].first){
                bfsTraversal(i,graph,visited);
                if(!isBipartiteGraph){
                    return false;
                }
            }
        }
        return true;
    }
};