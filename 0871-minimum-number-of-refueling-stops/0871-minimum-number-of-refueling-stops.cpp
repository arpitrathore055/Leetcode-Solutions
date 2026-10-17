class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
  
        int minRefuelStopsCount=0;
        
        sort(begin(stations),end(stations));
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        int stationPointer=0;
        long long reachable=startFuel;
        
        while(reachable < target){
            
            while(stationPointer < stations.size() && stations[stationPointer][0]<=reachable){
                pq.push({stations[stationPointer][1],stations[stationPointer][0]});
                stationPointer++;
            }
            
            if(pq.empty()){
                return -1;
            }
            
            int maxGasAvailable=pq.top().first;
            pq.pop();
            reachable+=maxGasAvailable;
            minRefuelStopsCount++;
            
        }
        
        return minRefuelStopsCount;
        
    }
};