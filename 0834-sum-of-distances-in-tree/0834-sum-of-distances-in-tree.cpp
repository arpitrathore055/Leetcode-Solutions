class Solution {
public:
    
    int N;
    
    void dfsTraversal(int source,int parent,vector<vector<int>>& adj,vector<int>& subtreeNodeCount,vector<int>& subtreeDistSum){
        
        for(auto child:adj[source]){
            
            //checking if parent
            if(child == parent){
                continue;
            }
            
            dfsTraversal(child,source,adj,subtreeNodeCount,subtreeDistSum);
            
            subtreeNodeCount[source]+=subtreeNodeCount[child];
            subtreeDistSum[source]+=subtreeDistSum[child] + subtreeNodeCount[child];
            
        }
        
    }
    
    void derootingDp(int source,int parent,vector<vector<int>>& adj,vector<int>& subtreeNodeCount,vector<int>& subtreeDistSum){
        
        if(parent != -1){
            subtreeDistSum[source]=subtreeDistSum[parent] + N - (2 * subtreeNodeCount[source]);
        }
        
        for(auto child:adj[source]){
            
            //checking if parent
            if(child == parent){
                continue;
            }
            
            derootingDp(child,source,adj,subtreeNodeCount,subtreeDistSum);
            
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        N=n;
        vector<vector<int>> adj(n);
        vector<int> subtreeNodeCount(n,1);
        vector<int> subtreeDistSum(n,0);
        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfsTraversal(0,-1,adj,subtreeNodeCount,subtreeDistSum);

        derootingDp(0,-1,adj,subtreeNodeCount,subtreeDistSum);

        return subtreeDistSum;
    }
};