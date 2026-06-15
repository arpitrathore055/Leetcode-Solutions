class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        vector<vector<int>> dist(n+1,vector<int>(k+2,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        dist[src][0]=0;
        pq.push({0,src,0});//cost,source,stops_taken

        while(!pq.empty()){
            auto [nodeCost,node,stops_taken]=pq.top();
            pq.pop();

            if(nodeCost > dist[node][stops_taken]){
                continue;
            }

            if(stops_taken >= k+1){
                continue;
            }

            for(auto vertices:adj[node]){
                int nextNode=vertices.first;
                int nextNodeCost=vertices.second;

                if(nodeCost + nextNodeCost < dist[nextNode][stops_taken+1]){
                    dist[nextNode][stops_taken+1]=nodeCost + nextNodeCost;
                    pq.push({dist[nextNode][stops_taken+1],nextNode,stops_taken+1});
                }
            }

        }
        int minFlightCost=INT_MAX;
        for(auto flight:dist[dst]){
            minFlightCost=min(minFlightCost,flight);
        }
        return (minFlightCost == INT_MAX)? -1:minFlightCost;
    }
};