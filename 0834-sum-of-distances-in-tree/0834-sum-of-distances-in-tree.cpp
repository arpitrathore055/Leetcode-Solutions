class Solution {
public:
    
    void dfsTraversal(int source,int parent,vector<vector<int>>& adj,vector<int>& subtreeNodesCount,vector<int>& subtreeDistSum){
        
        for(auto& child:adj[source]){
            
            if(child == parent){
                continue;
            }
            
            dfsTraversal(child,source,adj,subtreeNodesCount,subtreeDistSum);
            
            subtreeNodesCount[source]+=subtreeNodesCount[child];
            subtreeDistSum[source]+=subtreeNodesCount[child] + subtreeDistSum[child];
            
        }
        
    }
    
    void derooting(int source,int parent,vector<vector<int>>& adj,vector<int>& subtreeNodesCount,vector<int>& subtreeDistSum,int& N){
        
        //making sure, we're not processing root again, since its already processed with initial dfs
        if(parent != -1){
            subtreeDistSum[source]=subtreeDistSum[parent] + (N - subtreeNodesCount[source]) - subtreeNodesCount[source];
        }
        
        for(auto& child:adj[source]){
            
            if(child == parent){
                continue;
            }
            
            derooting(child,source,adj,subtreeNodesCount,subtreeDistSum,N);
            
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<int> subtreeNodesCount(n,1);
        vector<int> subtreeDistSum(n,0);
        
        vector<vector<int>> adj(n);
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        dfsTraversal(0,-1,adj,subtreeNodesCount,subtreeDistSum);
        derooting(0,-1,adj,subtreeNodesCount,subtreeDistSum,n);
        
        return subtreeDistSum;
        
    }
};