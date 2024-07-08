class Solution {
public:

    int dfsTraversal(int source,int n,unordered_map<int,vector<int>>&tree,vector<bool>&hasApple,vector<bool>&visited){
        if(tree.find(source)==tree.end()){
            return (hasApple[source])?2:0;
        }
        visited[source]=true;
        int totalTime=0;
        for(auto& v:tree[source]){
            if(!visited[v]){
                totalTime+=dfsTraversal(v,n,tree,hasApple,visited);
            }
        }
        if(totalTime>0){
            return totalTime+2;
        }
        return (hasApple[source])?totalTime+2:totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>tree;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<bool>visited(n,false);
        int timereq=dfsTraversal(0,n,tree,hasApple,visited);
        return (timereq>0)?timereq-2:timereq;
    }
};