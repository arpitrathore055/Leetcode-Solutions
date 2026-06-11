class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];

            adj[u].push_back({v,wt});
        }

        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,src});//cost,stops,node
        dist[src][0]=0;//[0]->stops and =0->cost

        while(!pq.empty()){

            auto frontNode=pq.top();
            pq.pop();
            int u=frontNode[2];
            int uCost=frontNode[0];
            int edges=frontNode[1];

            if(u == dst){
                return uCost;
            }

            if(edges == k+1){
                continue;
            }

            for(auto vertices:adj[u]){
                int v=vertices.first;
                int vCost=vertices.second;

                if( uCost + vCost < dist[v][edges+1]){
                    dist[v][edges+1]=uCost + vCost;
                    pq.push({uCost+vCost,edges+1,v});
                }

            }

        }
        return -1;

    }
};