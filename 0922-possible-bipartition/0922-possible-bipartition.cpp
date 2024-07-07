class Solution {

    bool isBipartite=true;

public:

    void dfsTraversal(int source,int colour,unordered_map<int,vector<int>>&umap,vector<bool>&visited,vector<int>&color){
        visited[source]=true;
        color[source]=colour;
        for(auto& v:umap[source]){
            if(!visited[v]){
                dfsTraversal(v,(colour==1)?2:1,umap,visited,color);
            }
            else{
                if(color[v]==colour){
                    isBipartite=false;
                    return;
                }
            }
        }
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>umap;
        for(auto& dislike:dislikes){
            int u=dislike[0];
            int v=dislike[1];
            umap[u].push_back(v);
            umap[v].push_back(u);
        }
        vector<bool>visited(n+1,false);
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfsTraversal(i,1,umap,visited,color);
                if(!isBipartite){
                    return false;
                }
            }
        }
        return true;
    }
};