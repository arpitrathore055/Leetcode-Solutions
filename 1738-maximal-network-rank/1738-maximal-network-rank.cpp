class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>deg(n,0);
        vector<vector<int>>connection(n,vector<int>(n));
        for(auto& road:roads){
            int u=road[0];
            int v=road[1];
            deg[u]++;
            deg[v]++;
            connection[u][v]=1;
            connection[v][u]=1;
        }
        int maxNetworkRank=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int currNetworkRank=0;
                currNetworkRank=(connection[i][j]==1)?deg[i]+deg[j]-1:deg[i]+deg[j];
                if(maxNetworkRank < currNetworkRank){
                    maxNetworkRank=currNetworkRank;
                }
            }
        }
        return maxNetworkRank;
    }
};